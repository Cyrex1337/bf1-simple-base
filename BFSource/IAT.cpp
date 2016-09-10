#include "IAT.hpp"

IAT::IAT( const char* module )
{
	m_ModuleBase = reinterpret_cast< uintptr_t >( GetModuleHandleA( module ) );

	if ( !IsValidPtr( m_ModuleBase ) )
		return;

	auto dos_header = reinterpret_cast< IMAGE_DOS_HEADER* >( m_ModuleBase );
	auto pe_header = reinterpret_cast< IMAGE_NT_HEADERS* >( m_ModuleBase + dos_header->e_lfanew );

	auto import_desc = reinterpret_cast< IMAGE_IMPORT_DESCRIPTOR* >( m_ModuleBase + pe_header->OptionalHeader.DataDirectory[ IMAGE_DIRECTORY_ENTRY_IMPORT ].VirtualAddress );

	m_FirstDescriptor = import_desc;
	m_FirstThunk = reinterpret_cast< IMAGE_THUNK_DATA* >( m_ModuleBase + import_desc->FirstThunk );
}

void IAT::ParseFor( const char* lib, const char* func )
{
	IMAGE_IMPORT_DESCRIPTOR* descriptor = nullptr;

	for ( auto cur = m_FirstDescriptor; IsValidPtr( cur ); cur++ )
	{
		if ( _stricmp( lib, reinterpret_cast< const char* >( m_ModuleBase + cur->Name ) ) == 0 )
		{
			descriptor = cur;
			break;
		}
	}

	if ( descriptor == nullptr )
		return;

	auto original_first_thunk = reinterpret_cast< IMAGE_THUNK_DATA* >( m_ModuleBase + descriptor->OriginalFirstThunk );
	m_HookIndex = 0;
	for ( auto cur = original_first_thunk; IsValidPtr( cur ); cur++ )
	{
		auto import_by_name = reinterpret_cast< IMAGE_IMPORT_BY_NAME* >( m_ModuleBase + cur->u1.AddressOfData );
		if ( _stricmp( func, import_by_name->Name ) == 0 )
			break;

		m_HookIndex++;
	}
}
