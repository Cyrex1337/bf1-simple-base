#include "EAT.hpp"

EAT::EAT( const char* module )
{
	m_ModuleBase = reinterpret_cast< uintptr_t >( GetModuleHandleA( module ) );
	auto dos_header = reinterpret_cast< IMAGE_DOS_HEADER* >( m_ModuleBase );
	auto pe_header = reinterpret_cast< IMAGE_NT_HEADERS* >( m_ModuleBase + dos_header->e_lfanew );

	m_ExportDir = reinterpret_cast< IMAGE_EXPORT_DIRECTORY* >( m_ModuleBase + pe_header->OptionalHeader.DataDirectory[ IMAGE_DIRECTORY_ENTRY_EXPORT ].VirtualAddress );
}

void EAT::ParseFor( const char* func )
{
	auto names = reinterpret_cast< uintptr_t* >( m_ModuleBase + m_ExportDir->AddressOfNames );
	auto name_ordinals = reinterpret_cast< WORD* >( m_ModuleBase + m_ExportDir->AddressOfNameOrdinals );

	unsigned int name_index;

	for ( name_index = 0; name_index < m_ExportDir->NumberOfNames; name_index++ )
		if ( _stricmp( func, reinterpret_cast< const char* >( m_ModuleBase + names[ name_index ] ) ) == 0 )
			break;

	m_HookIndex = name_ordinals[ name_index ];
}
