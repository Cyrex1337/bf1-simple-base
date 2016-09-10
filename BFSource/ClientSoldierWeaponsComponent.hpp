#pragma once

namespace fb
{
	class ClientSoldierWeaponsComponent
	{
	public:
		char _0x0000[ 16 ];
		SoldierWeaponsComponentData* N0033DA3B; //0x0010 [SoldierWeaponsComponentData]
		char _0x0018[ 2192 ];
		ClientAnimatedSoldierWeaponHandler* m_handler; //0x08A8 Smart[ClientSoldierWeapon]
		char _0x08B0[ 56 ];
		__int64 m_pClientAntAnimatableEntity1; //0x08E8 [ClientAntAnimatableEntity]
		__int64 m_pClientAntAnimatableEntity2; //0x08F0 [ClientAntAnimatableEntity]
		ClientSoldierEntity* m_pOwner; //0x08F8 [ClientSoldierEntity]
		ClientActiveWeaponHandler* m_pActiveWeaponHandler; //0x0900 
		char _0x0908[ 88 ];
		__int32 m_ActiveSlot; //0x0960 
		__int32 m_LastActiveSlot; //0x0964 
		__int32 m_LastGunIndex; //0x0968 
		char _0x096C[ 32 ];
		__int32 m_CurrentZoomLevel; //0x098C 
		__int32 m_MaxZoomLevel; //0x0990 
		char _0x0994[ 684 ];


	};//Size=0x0C40
}