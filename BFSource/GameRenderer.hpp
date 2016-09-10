#pragma once

namespace fb
{
	class GameRenderer
	{
	public:
		static GameRenderer* Instance( )
		{
			return *reinterpret_cast< GameRenderer** >( 0x143523700 );
		}

	public:
		char _0x0000[ 64 ];
		GameRenderSettings* m_pGameRenderSettings; //0x0040 [GameRenderSettings]
		char _0x0048[ 16 ];
		RenderView* m_pRenderView; //0x0058 
		char _0x0060[ 992 ];

	};//Size=0x0440
}