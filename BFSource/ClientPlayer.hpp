#pragma once

namespace fb
{
	class ClientPlayer
	{
	public:
		ClientSoldierEntity* GetSoldier( )
		{
			return m_Soldier.get_data( );
		}

	public:
		virtual ~ClientPlayer( );
		virtual ClientCharacterEntity* GetCharacterEntity( ); // ClientSoldierEntity + 188 
		virtual DWORD_PTR GetCharacterUserData( ); // PlayerCharacterUserData
		virtual EntryComponent* GetEntryComponent( );  //soldier + 128h
		virtual bool InVehicle( );//1dc5 bf1
		virtual unsigned int getId( );//1d74 bf1
		virtual bool hasUnlockAsset( LPVOID, bool );
		virtual void getUnlockAssets( eastl::vector<LPVOID> * );
		virtual bool isUnlocked( LPVOID );
		PlayerData* m_pPlayerData; //0x0008 [PlayerData]
		char _0x0010[ 8 ];
		char* m_Name; //0x0018 
		char _0x0020[ 32 ];
		char szName[ 32 ]; //0x0040 
		char _0x0060[ 4424 ];
		VeniceSoldierCustomizationAsset* m_pSelectedVeniceSoldierCustomizationAsset; //0x11A8 [VeniceSoldierCustomizationAsset]
		char _0x11B0[ 2689 ];
		BYTE m_IsAIPlayer; ; //0x1C31 
		char _0x1C32[ 2 ];
		__int32 m_TeamId; //0x1C34 
		char _0x1C38[ 232 ];
		eastl::weakptr<ClientSoldierEntity> m_Corpse; //0x1D20 
		eastl::weakptr<ClientSoldierEntity> m_Soldier; //0x1D28 Weak[ClientSoldierEntity]
		eastl::weakptr<ClientPlayer> m_Player; //0x1D30 
		ClientVehicleEntity* m_pAttachedControllable; //0x1D38 
		__int32 m_AttachedEntryId; //0x1D40 
		char _0x1D44[ 4 ];
		ClientSoldierEntity* m_pControlledControllable; //0x1D48 [ClientSoldierEntity]
		__int32 m_ControlledEntryId; //0x1D50 
		char _0x1D54[ 748 ];

	};//Size=0x2040
}
