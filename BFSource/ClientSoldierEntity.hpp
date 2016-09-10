#pragma once

namespace fb
{
	class ClientSoldierEntity
	{
	public:
		bool GetBonePos( unsigned int bone_id, D3DXVECTOR3& out )
		{
			*reinterpret_cast< byte* >( reinterpret_cast< uintptr_t >( this ) + 0x1A ) = 161;
			auto ragdoll_component = *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( this ) + 0x460 );

			if ( !IsValidPtr( ragdoll_component ) )
				return false;

			auto quat = *reinterpret_cast< uintptr_t* >( ragdoll_component + 0x20 );

			if ( !IsValidPtr( quat ) )
				return false;

			D3DXVECTOR3 tmp;
			tmp = *reinterpret_cast< D3DXVECTOR3* >( quat + bone_id * 0x20 );
			out.x = tmp.x;
			out.y = tmp.y;
			out.z = tmp.z;

			return true;
		}

	public:
		__int64 vtable; //0x0000 
		eastl::weakptr<ClientSoldierWeapon> m_ActiveSoldierWeapon; //0x0008 Weak[ClientSoldierWeapon]
		eastl::weakptr<ClientSoldierEntity> m_Soldier; //0x0010 Weak[ClientSoldierEntity]
		char _0x0018[ 24 ];
		SoldierEntityData* m_pSoldierEntityData; //0x0030 [SoldierEntityData]
		char _0x0038[ 56 ];
		ClientSoldierPhysicsComponent* m_pBFClientSoldierPhysicsComponent; //0x0070 [BFClientSoldierPhysicsComponent]
		char _0x0078[ 184 ];
		ClientCharacterSpawnEntity* m_pClientCharacterSpawnEntity; //0x0130 [ClientCharacterSpawnEntity]
		char _0x0138[ 136 ];
		ClientSoldierHealthComponent* m_pBFClientSoldierHealthComponent; //0x01C0 [BFClientSoldierHealthComponent]
		char _0x01C8[ 112 ];
		ClientSoldierEntity* m_Soldier0; //0x0238 [ClientSoldierEntity]
		SoldierBlueprint* m_pSoldierBlueprint; //0x0240 [SoldierBlueprint]
		char _0x0248[ 24 ];
		ClientPlayer* m_pPlayer; //0x0260 
		ClientAntAnimatableEntity* m_pClientAntAnimatableEntity; //0x0268 [ClientAntAnimatableEntity]
		ClientAntAnimatableEntity* m_pClientAntAnimatableEntity2; //0x0270 [ClientAntAnimatableEntity]
		VeniceClientSoldierCameraComponent* m_pVeniceClientSoldierCameraComponent; //0x0278 [VeniceClientSoldierCameraComponent]
		char _0x0280[ 48 ];
		VeniceClientSoldierCameraComponent* m_pVeniceClientSoldierCameraComponent1; //0x02B0 [VeniceClientSoldierCameraComponent]
		char _0x02B8[ 88 ];
		SoldierEntityData* m_pSoldierEntityData2; //0x0310 [SoldierEntityData]
		char _0x0318[ 608 ];
		ClientSoldierPrediction* m_pClientSoldierPrediction; //0x0578 
		char _0x0580[ 20 ];
		float m_authorativeYaw; //0x0594 
		char _0x0598[ 44 ];
		float m_authorativePitch; //0x05C4 
		__int32 m_PoseType; //0x05C8 
		BYTE m_RenderFlags; //0x05CC 
		BYTE m_EngineChams; //0x05CD 
		char _0x05CE[ 90 ];
		ClientSoldierWeaponsComponent* m_pClientSoldierWeaponsComponent; //0x0628 [ClientSoldierWeaponsComponent]
		ClientSoldierBodyComponent* m_pClientSoldierBodyComponent; //0x0630 [ClientSoldierBodyComponent]
		ClientSoldierBreathControlComponent* m_pClientSoldierBreathControlComponent; //0x0638 [ClientSoldierBreathControlComponent]
		ClientVehicleEntryListenerComponent* m_pClientBFVehicleEntryListenerComponent; //0x0640 [ClientBFVehicleEntryListenerComponent]
		ClientAimEntity* m_pClientAimEntity; //0x0648 [ClientAimEntity]
		ClientSoldierWeapon* m_pActiveSoldierWeapon; //0x0650 [ClientSoldierWeapon]
		ClientMovementComponent* m_pClientMovementComponent; //0x0658 [ClientMovementComponent]
		char _0x0660[ 24 ];
		BYTE m_isSprinting; //0x0678 
		BYTE m_Occluded; //0x0679 
		char _0x067A[ 694 ];
		ClientBoneComponent* m_pClientBoneComponent; //0x0930 [ClientBoneComponent]
		char _0x0938[ 1336 ];
		ClientSoldierParachuteComponent* m_pClientSoldierParachuteComponent; //0x0E70 [ClientSoldierParachuteComponent]
		char _0x0E78[ 600 ];
		ClientSpottingComponent* m_pClientSpottingComponent; //0x10D0 [ClientSpottingComponent]
		char _0x10D8[ 24 ];
		ClientSpottingTargetComponent* m_pClientSpottingTargetComponent; //0x10F0 [ClientSpottingTargetComponent]
		char _0x10F8[ 56 ];
		ClientSoldierLeaningComponent* m_pClientSoldierLeaningComponent; //0x1130 [ClientSoldierLeaningComponent]
		char _0x1138[ 24 ];
		ClientSoldierSuppressionComponent* m_pClientSoldierSuppressionComponent; //0x1150 [ClientSoldierSuppressionComponent]
		char _0x1158[ 24 ];
		ClientDeathDropKitComponent* m_pClientDeathDropKitComponent; //0x1170 [ClientDeathDropKitComponent]
		char _0x1178[ 24 ];
		ClientClimbLadderComponent* m_pClientClimbLadderComponent; //0x1190 [ClientClimbLadderComponent]
		char _0x1198[ 120 ];
		ClientHitReactionComponent* m_pClientHitReactionComponent; //0x1210 [ClientHitReactionComponent]
		char _0x1218[ 24 ];
		ClientVaultComponent* m_pClientVaultComponent; //0x1230 [ClientVaultComponent]
		char _0x1238[ 1576 ];

	};//Size=0x1860
}
