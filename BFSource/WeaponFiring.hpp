#pragma once

namespace fb
{
	class WeaponFiring
	{
	public:
		char _0x0000[ 128 ];
		char pad[ 0x8 /***/ ];
		char _0x0098[ 288 ];
		__int32 m_Ammo; //0x01B8 
		__int32 m_ExtraAmmo; //0x01BC 
		char _0x01C0[ 4 ];
		BYTE m_hasStoppedFiring; //0x01C4 
		BYTE m_primaryFireTriggeredLastFrame; //0x01C5 
		BYTE m_isOverheated; //0x01C6 
		char _0x01C7[ 73 ];
		WeaponModifier* m_pWeaponModifier; //0x0210 
		char _0x0218[ 552 ];

	};//Size=0x0440
}