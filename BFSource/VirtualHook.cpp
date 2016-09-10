#include "VirtualHook.hpp"

VirtualHook::VirtualHook( void* instance, bool shadowed )
{
	if ( !IsValidPtr( instance ) )
		return;

	m_pInstance = static_cast< uintptr_t** >( instance );
	m_pOriginalTable = *m_pInstance;

	if ( !IsValidPtr( m_pOriginalTable ) )
		return;

	for ( unsigned int i = 0; IsValidPtr( m_pOriginalTable[ i ] ); i++ )
		m_NumberOfVirtuals++;

	if ( m_NumberOfVirtuals == 0 )
		return;

	if ( shadowed )
	{
		m_pShadowTable = std::shared_ptr<uintptr_t>( new uintptr_t[ m_NumberOfVirtuals ] );
		memcpy( m_pShadowTable.get( ), m_pOriginalTable, sizeof( uintptr_t ) * m_NumberOfVirtuals );
		*m_pInstance = m_pShadowTable.get( );
		m_Shadowed = true;
	}
}

VirtualHook::~VirtualHook( )
{
	UnhookTable( );
}

void VirtualHook::UnhookPtr( unsigned int index )
{
	if ( m_Shadowed )
		m_pShadowTable.get( )[ index ] = m_pOriginalTable[ index ];
	else
	{
		DWORD old;
		VirtualProtect( &m_pOriginalTable[ index ], sizeof( uintptr_t ), PAGE_EXECUTE_READWRITE, &old );
		m_pOriginalTable[ index ] = m_HooksMap[ index ];
		VirtualProtect( &m_pOriginalTable[ index ], sizeof( uintptr_t ), PAGE_EXECUTE_READWRITE, &old );
	}
}

void VirtualHook::UnhookTable( )
{
	if ( m_Shadowed )
		*m_pInstance = m_pOriginalTable;
	else
	{
		for ( auto elem : m_HooksMap )
		{
			DWORD old;
			VirtualProtect( &m_pOriginalTable[ elem.first ], sizeof( uintptr_t ), PAGE_EXECUTE_READWRITE, &old );
			m_pOriginalTable[ elem.first ] = elem.second;
			VirtualProtect( &m_pOriginalTable[ elem.first ], sizeof( uintptr_t ), PAGE_EXECUTE_READWRITE, &old );
		}
	}
}

void VirtualHook::RehookTable( void* instance, bool shadowed )
{
	if ( instance )
	{
		UnhookTable( );

		if ( !IsValidPtr( instance ) )
			return;

		m_pInstance = static_cast< uintptr_t** >( instance );
		m_pOriginalTable = *m_pInstance;

		if ( !IsValidPtr( m_pOriginalTable ) )
			return;

		m_NumberOfVirtuals = 0;
		for ( unsigned int i = 0; IsValidPtr( m_pOriginalTable[ i ] ); i++ )
			m_NumberOfVirtuals++;

		if ( m_NumberOfVirtuals == 0 )
			return;

		if ( shadowed )
		{
			m_pShadowTable = std::shared_ptr<uintptr_t>( new uintptr_t[ m_NumberOfVirtuals ] );
			memcpy( m_pShadowTable.get( ), m_pOriginalTable, sizeof( uintptr_t ) * m_NumberOfVirtuals );
			*m_pInstance = m_pShadowTable.get( );
			m_Shadowed = true;
		}
	}
	else if ( m_Shadowed )
		*m_pInstance = m_pShadowTable.get( );
}
