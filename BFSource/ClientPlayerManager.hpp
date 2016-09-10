#pragma once

namespace fb
{
	class ClientPlayerManager
	{
	public:
		ClientPlayer* GetLocalPlayer( ) const
		{
			return m_pLocalPlayer;
		}

	public:
		virtual ~ClientPlayerManager( );
		virtual eastl::vector<ClientPlayer*>* getPlayers( );//D0
		virtual eastl::vector<ClientPlayer*>* getSpectators( );

		PlayerData* m_pPlayerData; //0x0008 [PlayerData]
		char _0x0010[ 1344 ];
		ClientPlayer** m_ppPlayers_0; //0x0550 
		char _0x0558[ 24 ];
		ClientPlayer** m_ppPlayers_1; //0x0570 
		ClientPlayer* m_pLocalPlayer; //0x0578 
		char _0x0580[ 704 ];

	};//Size=0x0840
}
