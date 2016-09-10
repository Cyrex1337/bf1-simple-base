#pragma once

namespace fb
{
	class ClientSoldierWeapon
	{
	public:
		char _0x0000[ 48 ];
		SoldierWeaponData* m_pSoldierWeaponData; //0x0030 [SoldierWeaponData]
		char _0x0038[ 18840 ];
		__int64 m_ZoomLevelData1; //0x49D0 [ZoomLevelData]
		__int64 ZoomLevelData2; //0x49D8 [ZoomLevelData]
		char _0x49E0[ 48 ];
		ClientWeapon* m_pWeapon; //0x4A10 [ClientWeapon]
		char _0x4A18[ 16 ];
		WeaponFiring* m_pPrimary; //0x4A28 
		char _0x4A30[ 1552 ];

	};//Size=0x5040
}