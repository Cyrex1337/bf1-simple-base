#pragma once

#include <Windows.h>
#include "Defines.hpp"

class IAT
{
public:
	IAT( const char* module );

public:
	void ParseFor( const char* lib, const char* func );
	
	template <typename T>
	T Hook( T proxy )
	{
		if ( !IsValidPtr( proxy ) )
			return 0;

		T original = reinterpret_cast< T >( m_FirstThunk[ m_HookIndex ].u1.Function );

		m_FirstThunk[ m_HookIndex ].u1.Function = reinterpret_cast< DWORD >( proxy );

		return original;
	}

private:
	uintptr_t m_ModuleBase;
	IMAGE_IMPORT_DESCRIPTOR* m_FirstDescriptor;
	IMAGE_THUNK_DATA* m_FirstThunk;
	unsigned int m_HookIndex;
};