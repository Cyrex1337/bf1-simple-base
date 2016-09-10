#pragma once

namespace fb
{
	class FiringFunctionData
	{
	public:
		char _0x0000[ 136 ];
		float m_initialSpeed; //0x0088 
		char _0x008C[ 52 ];
		BulletEntityData* m_pBulletEntityData; //0x00C0 [BulletEntityData]
		char _0x00C8[ 24 ];
		__int32 m_numberOfBulletsPerShell; //0x00E0 
		__int32 m_numberOfBulletsPerShot; //0x00E4 
		__int32 m_numberOfBulletsPerBurst; //0x00E8 
		char _0x00EC[ 4 ];
		BYTE m_relativeTargetAiming; //0x00F0 
		BYTE m_forceSpawnToCamera; //0x00F1 
		BYTE m_activeForceSpawnToCamera; //0x00F2 
		BYTE m_SpawnVisualAtBone; //0x00F3 
		char _0x00F4[ 256 ];
		float m_TriggerPullWeight; //0x01F4 
		float m_RateOfFire; //0x01F8 
		float m_RateOfFireForBurst; //0x01FC 
		float m_ClientFireRateMultiplier; //0x0200 
		float m_ReloadDelay; //0x0204 
		float m_ReloadTime; //0x0208 

	};//Size=0x0440
}