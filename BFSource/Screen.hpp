#pragma once

namespace fb
{
	class ScreenInfo
	{
	public:
		int32_t m_width;
		int32_t m_height;
		int32_t m_winWidth;
		int32_t m_winHeight;
		float	m_fullscreenRefreshRate;
	};

	class Screen
	{
	public:
		uint8_t               pad00[ 0x8 ];
		uintptr_t             m_windowHandle;
		uint8_t               pad01[ 0x4c ];
		uint8_t               m_isTopWindow;
		uint8_t               m_isMinimized;
		uint8_t               m_isMaximized;
		uint8_t               m_isResizing;
		uint8_t               pad02[ 0x8 ];
		ScreenInfo            m_screenInfo;
		uint8_t               pad03[ 0x1fc ];
		IDXGISwapChain        *m_swapChain;
		uint8_t               pad04[ 0x20 ];
		uintptr_t		      m_defaultRenderView;
	};
}
