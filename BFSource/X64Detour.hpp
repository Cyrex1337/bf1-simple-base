#pragma once

#include "Defines.hpp"
#include <cstdint>
#include <Windows.h>

class X64Detour
{
public:
	X64Detour( void* address );
	~X64Detour( );

public:
	template <typename T>
	T Hook( T destination, unsigned int length, bool is_api = false )
	{
			m_Length = length;
			m_pDestination = reinterpret_cast< byte* >( destination );

			MEMORY_BASIC_INFORMATION mbi;
			for ( auto ptr = m_pSource; ptr > m_pSource - 0x80000000; ptr = reinterpret_cast< byte* >( mbi.BaseAddress ) - 1 )
			{
				if ( !VirtualQuery( ptr, &mbi, sizeof( MEMORY_BASIC_INFORMATION ) ) )
					break;

				if ( mbi.State != MEM_FREE )
					continue;

				m_pCodeCave = static_cast< byte* >( VirtualAlloc( mbi.BaseAddress, 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE ) );
				if ( m_pCodeCave ) break;
			}

			if ( !m_pCodeCave )
				return nullptr;

			memcpy( m_pCodeCave, m_pSource, length );
			BYTE detour[ ] = { 0x50, 0x48, 0xB8, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x48, 0x87, 0x04, 0x24, 0xC3 };
			memcpy( m_pCodeCave + length, detour, sizeof( detour ) );
			*reinterpret_cast< uintptr_t* >( m_pCodeCave + length + 3 ) = reinterpret_cast< uintptr_t >( m_pSource + length );

			DWORD old;
			VirtualProtect( m_pSource, length, PAGE_EXECUTE_READWRITE, &old );

			if ( is_api )
			{
				memcpy( m_pSource, detour, sizeof( detour ) );
				*reinterpret_cast< uintptr_t* >( m_pSource + 3 ) = reinterpret_cast< uintptr_t >( m_pDestination );
			}
			else
			{
				m_pSource[ 0 ] = 0xFF;
				m_pSource[ 1 ] = 0x25;
				*reinterpret_cast< uint32_t* >( m_pSource + 2 ) = m_pDestination - m_pSource - 6;
			}

			for ( unsigned int i = 6; i < length; i++ )
				m_pSource[ i ] = 0x90;

			VirtualProtect( m_pSource, length, old, &old );
	}

	void Unhook( ) const;
	void Rehook( void* address = nullptr, unsigned int length = 0 ) const;

private:
	byte* m_pCodeCave;
	byte* m_pSource;
	byte* m_pDestination;

	unsigned int m_Length;
};