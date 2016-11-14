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
	bool WorldToScreen( const DirectX::XMFLOAT3& world_point, DirectX::XMFLOAT3& out );
	void HandleDXScreenshot( );
}
