#include "X86Detour.h"

X86Detour::X86Detour( void* address )
{
	m_pSource = static_cast< byte* >( address );
}

X86Detour::~X86Detour( )
{
	Unhook( );
}

void X86Detour::Unhook( ) const
{
	DWORD old;
	VirtualProtect( m_pSource, m_Length, PAGE_EXECUTE_READWRITE, &old );
	memcpy( m_pSource, m_pCodeCave, m_Length );
	VirtualProtect( m_pSource, m_Length, old, &old );

	VirtualFree( m_pCodeCave, 0, MEM_RELEASE );
}

void X86Detour::Rehook( void* address, unsigned int length ) const
{
	if(address == nullptr)
	{
		DWORD old;
		VirtualProtect( m_pSource, length, PAGE_EXECUTE_READWRITE, &old );

		*m_pSource = 0xE9;
		*reinterpret_cast< uintptr_t* >( m_pSource + 1 ) = reinterpret_cast< uintptr_t >( m_Destination ) - reinterpret_cast< uintptr_t >( m_pSource ) - 5;
		for ( unsigned int i = 5; i < length; i++ )
			*( m_pSource + i ) = 0x90;

		VirtualProtect( m_pSource, length, old, &old );
	}
}
