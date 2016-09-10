#pragma once

#include <memory>
#include <unordered_map>
#include <cstdint>
#include <Windows.h>

#include "Defines.hpp"

class VirtualHook
{
public:
	VirtualHook( void* instance, bool shadowed = false );
	~VirtualHook( );

public:
	template <typename T>
	T Hook( unsigned int index, T ptr )
	{
		if ( !( index < m_NumberOfVirtuals ) )
			return nullptr;

		T original_ptr = reinterpret_cast< T >( m_pOriginalTable[ index ] );
		m_HooksMap[ index ] = reinterpret_cast< uintptr_t >( original_ptr );

		if ( m_Shadowed )
			m_pShadowTable.get( )[ index ] = reinterpret_cast< uintptr_t >( ptr );
		else
		{
			DWORD old;
			VirtualProtect( &m_pOriginalTable[ index ], sizeof( uintptr_t ), PAGE_EXECUTE_READWRITE, &old );
			m_pOriginalTable[ index ] = reinterpret_cast< uintptr_t >( ptr );
			VirtualProtect( &m_pOriginalTable[ index ], sizeof( uintptr_t ), PAGE_EXECUTE_READWRITE, &old );
		}

		return original_ptr;
	}

	void UnhookPtr( unsigned int index );

	void UnhookTable( );
	void RehookTable( void* instance = nullptr, bool shadowed = false );

private:
	uintptr_t** m_pInstance;
	uintptr_t* m_pOriginalTable;

	std::shared_ptr<uintptr_t> m_pShadowTable;
	std::unordered_map<unsigned int, uintptr_t> m_HooksMap;

	unsigned int m_NumberOfVirtuals = 0;
	bool m_Shadowed = false;
};