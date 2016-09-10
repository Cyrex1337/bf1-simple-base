#include "SDK.hpp"
#include "Utils.hpp"
#include "Hooks.hpp"

void InitialThread()
{
	Utils::SpawnConsole( "Log" );

	// gdi32.dll is actually a 32-bit module but it is mapped very high in memory so you have to use the absolute detour
	// (absolute detour: doesn't use JMPs or JCCs but PUSH + RETN method)
	// ATTENTION: YOU STILL NEED TO CALL THE ORIGINAL BY USING __stdcall (x86), NOT __fastcall (x64)
	//X64Detour detour( GetProcAddress( GetModuleHandleA( "Gdi32.dll" ), "BitBlt" ) );
	// length = 18
	//detour.Hook( Hooks::hkBitBlt, 18, true );

	// setup a vftable-swap hook
	VirtualHook present_hook( fb::DXRenderer::Instance( )->m_pScreen->m_swapChain, true );
	oPresent = present_hook.Hook( 8, Hooks::hkPresent );
}

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if ( dwReason == DLL_PROCESS_ATTACH )
		CreateThread( nullptr, 0, reinterpret_cast< LPTHREAD_START_ROUTINE >( InitialThread ), nullptr, 0, nullptr );

	return TRUE;
}