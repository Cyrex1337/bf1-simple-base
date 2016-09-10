#pragma once

#include <Windows.h>

class EAT
{
public:
	EAT( const char* module );

public:
	void ParseFor( const char* func );

	template <typename T>
	T Hook( T proxy )
	{
		auto exports = reinterpret_cast< uintptr_t* >( m_ModuleBase + m_ExportDir->AddressOfFunctions );
		exports[ m_HookIndex ] = reinterpret_cast< uintptr_t >( proxy ) - m_ModuleBase;
	}

private:
	uintptr_t m_ModuleBase;
	IMAGE_EXPORT_DIRECTORY* m_ExportDir;
	unsigned int m_HookIndex;
};