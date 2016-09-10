#pragma once

namespace fb
{
	class ClientGameContext
	{
	public:
		static ClientGameContext* Instance( )
		{
			return *reinterpret_cast< ClientGameContext** >( 0x14333C680 );
		}

	public:
		ClientPlayerManager* GetPlayerManager( ) const
		{
			return m_pClientPlayerManager_1;
		}

	public:
		char _0x0000[ 16 ];
		__int64 m_messageManager; //0x0010 
		char _0x0018[ 8 ];
		ClientPlayerManager * m_pClientPlayerManager_0; //0x0020 
		GameTime* m_pGameTime; //0x0028 
		Level* m_pLevel; ; //0x0030 
		char _0x0038[ 48 ];
		ClientPlayerManager * m_pClientPlayerManager_1; //0x0068 
		OnlineManager* m_pOnlineManager; //0x0070 
		GameView * m_pGameView; //0x0078 [GameView]
		char _0x0080[ 960 ];

	};//Size=0x0440
}
