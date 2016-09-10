#pragma once

namespace fb
{
	class WeaponFiringData
	{
	public:
		char _0x0000[ 16 ];
		FiringFunctionData* m_FiringFunctionData; //0x0010 [FiringFunctionData]
		char _0x0018[ 24 ];
		GunSwayData* m_pGunSwayData; //0x0030 [GunSwayData]
		char _0x0038[ 8 ];

	};//Size=0x0040
}