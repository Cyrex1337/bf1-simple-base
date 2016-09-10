#pragma once

#include "SDK.hpp"

extern bool g_CanRender;

using PresentFn = HRESULT( __stdcall* )( IDXGISwapChain*, UINT, UINT );
extern PresentFn oPresent;

namespace Hooks
{
	//int32_t __stdcall hkBitBlt( HDC hdc_dest, int32_t x_dest, int32_t y_dest, int32_t width, int32_t height, HDC hdc_source, int32_t x_source, int32_t y_source, uint32_t raster_operation );
	HRESULT __stdcall hkPresent( IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags );
}
