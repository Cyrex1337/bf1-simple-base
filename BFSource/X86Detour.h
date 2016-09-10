#pragma once

#include "Defines.hpp"
#include <cstdint>
#include <Windows.h>

class X86Detour
{
public:
	X86Detour( void* address );
	~X86Detour( );

public:
	template <typename T>
	T Hook( T destination, unsigned int length )
	{
		m_Length = length;
		m_Destination = reinterpret_cast< byte* >( destination );

		m_pCodeCave = static_cast< byte* >( VirtualAlloc( nullptr, length + 5, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE ) );

		memcpy( m_pCodeCave, m_pSource, length );
		*( m_pCodeCave + length ) = 0xE9;
		*reinterpret_cast< uintptr_t* >( m_pCodeCave + length + 1 ) = m_pSource + length - m_pCodeCave - length - 5;

		DWORD old;
		VirtualProtect( m_pSource, length, PAGE_EXECUTE_READWRITE, &old );

		*m_pSource = 0xE9;
		*reinterpret_cast< uintptr_t* >( m_pSource + 1 ) = reinterpret_cast< uintptr_t >( destination ) - reinterpret_cast< uintptr_t >( m_pSource ) - 5;
		for ( unsigned int i = 5; i < length; i++ )
			*( m_pSource + i ) = 0x90;

		VirtualProtect( m_pSource, length, old, &old );

		return reinterpret_cast< T >( m_pCodeCave );
	}

	void Unhook( ) const;
	void Rehook( void* address = nullptr, unsigned int length = 0 ) const;

private:
	byte* m_pCodeCave;
	byte* m_pSource;
	byte* m_Destination;

	unsigned int m_Length;
};