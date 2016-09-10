#pragma once

#include "X64Detour.hpp"

X64Detour::X64Detour(void* address)
{
	m_pSource = static_cast< byte* >( address );
}

X64Detour::~X64Detour( )
{

}

void X64Detour::Unhook( ) const
{
	DWORD old;
	VirtualProtect( m_pSource, m_Length, PAGE_EXECUTE_READWRITE, &old );
	memcpy( m_pSource, m_pCodeCave, m_Length );
	VirtualProtect( m_pSource, m_Length, old, &old );

	VirtualFree( m_pCodeCave, 0, MEM_RELEASE );
}

void X64Detour::Rehook( void* address, unsigned length ) const
{
	if ( address == nullptr )
	{
		DWORD old;
		VirtualProtect( m_pSource, m_Length, PAGE_EXECUTE_READWRITE, &old );
		m_pSource[ 0 ] = 0xFF;
		m_pSource[ 1 ] = 0x25;
		*reinterpret_cast< uintptr_t* >( m_pSource + 2 ) = m_pDestination - m_pSource - 6;
		for ( unsigned int i = 6; i < m_Length; i++ )
			m_pSource[ i ] = 0x90;
		VirtualProtect( m_pSource, m_Length, old, &old );
	}
}
