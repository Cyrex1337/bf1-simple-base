#pragma once

namespace fb
{
	class DXRenderer
	{
	public:
		static DXRenderer* Instance( )
		{
			return *reinterpret_cast< DXRenderer** >( 0x143525658 );
		}

	public:
		char _0x0000[ 2000 ];
		__int32 m_frameCounter; //0x07D0 
		__int32 m_framesInProgress; //0x07D4 
		__int32 m_framesInProgress2; //0x07D8 
		BYTE m_isActive; //0x07DC 
		char _0x07DD[ 3 ];
		Screen* m_pScreen; //0x07E0 
		char _0x07E8[ 64 ];
		DXDisplaySettings* m_pDx11DisplaySettings; //0x0828 [Dx11DisplaySettings]
		char _0x0830[ 48 ];
		ID3D11Device* m_pDevice; //0x0860 
		ID3D11DeviceContext* m_pContext; //0x0868 
		char _0x0870[ 104 ];
		char* m_AdapterName; //0x08D8 
		char _0x08E0[ 2912 ];

	};
}