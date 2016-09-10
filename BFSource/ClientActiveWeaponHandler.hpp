#pragma once

namespace fb
{
	class ClientActiveWeaponHandler
	{
	public:
		char _0x0000[ 56 ];
		ClientSoldierWeapon* m_pWeapon; //0x0038 [ClientSoldierWeapon]
		char _0x0040[ 24 ];
		ClientSoldierEntity* m_pOwner; //0x0058 [ClientSoldierEntity]
		char _0x0060[ 96 ];

	};//Size=0x00C0
}