#pragma once

#include "SDK.hpp"
#include <iostream>

#include "EAT.hpp"
#include "IAT.hpp"
#include "VEH.hpp"
#include "VirtualHook.hpp"
#include "X64Detour.hpp"
#include "X86Detour.h"

namespace Utils
{
	void SpawnConsole( const char* title = nullptr );
	bool WorldToScreen( const D3DXVECTOR3& world_point, D3DXVECTOR3& out );
	void HandleDXScreenshot( );
}
