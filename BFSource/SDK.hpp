#pragma once

#include <Windows.h>
#include <stdio.h>
#include <D3D11.h>
#include <D3DX10math.h>

#include "Defines.hpp"
#include "eastl_includes.hpp"

namespace fb
{
	class ClientGameContext;
	class ClientPlayerManager;
	class ClientPlayer;
	class ClientSoldierEntity;
	class DXRenderer;
	class GameRenderer;
	class Level;
	class OnlineManager;
	class RenderView;
	class GameTime;
	class GameView;
	class GameRenderSettings;
	class Screen;
	class DXDisplaySettings;
	class LevelData;
	class TeamEntityData;
	class PhysicsManager;
	class ClientPeer;
	class ClientConnection;
	class PlayerData;
	class ClientCharacterEntity;
	class EntryComponent;
	class VeniceSoldierCustomizationAsset;
	class ClientVehicleEntity;
	class ClientSoldierWeapon;
	class SoldierEntityData;
	class ClientSoldierPhysicsComponent;
	class ClientCharacterSpawnEntity;
	class ClientSoldierHealthComponent;
	class SoldierBlueprint;
	class ClientAntAnimatableEntity;
	class VeniceClientSoldierCameraComponent;
	class ClientSoldierPrediction;
	class ClientSoldierWeaponsComponent;
	class ClientSoldierBodyComponent;
	class ClientSoldierBreathControlComponent;
	class ClientVehicleEntryListenerComponent;
	class ClientAimEntity;
	class ClientMovementComponent;
	class ClientBoneComponent;
	class ClientSoldierParachuteComponent;
	class ClientSpottingComponent;
	class ClientSpottingTargetComponent;
	class ClientSoldierLeaningComponent;
	class ClientSoldierSuppressionComponent;
	class ClientDeathDropKitComponent;
	class ClientClimbLadderComponent;
	class ClientHitReactionComponent;
	class ClientVaultComponent;
	class SoldierHealthComponentData;
	class SoldierWeaponsComponentData;
	class ClientAnimatedSoldierWeaponHandler;
	class ClientActiveWeaponHandler;
	class AimEntityData;
	class ClientSoldierAimingSimulation;
	class SoldierWeaponData;
	class ClientWeapon;
	class WeaponFiring;
	class WeaponFiringData;
	class SoldierAimingSimulationData;
	class SoldierWeaponBlueprint;
	class FiringFunctionData;
	class GunSwayData;
	class SoldierAimAssistData;
	class WeaponData;
	class WeaponModifier;
	class UnlockAssetBase;
	class BulletEntityData;
	class FpsAimer;
	class DebugRenderer2;
	class Color32;
}

enum BoneIds
{
	BONE_Reference = 0x0,
	BONE_AITrajectory = 0x1,
	BONE_Trajectory = 0x2,
	BONE_TrajectoryEnd = 0x3,
	BONE_Hips = 0x4,
	BONE_Spine = 0x5,
	BONE_Spine1 = 0x6,
	BONE_Spine2 = 0x7,
	BONE_LeftShoulder = 0x8,
	BONE_LeftShoulder_Phys = 0x9,
	BONE_LeftArm = 0xA,
	BONE_LeftArmRoll = 0xB,
	BONE_LeftArm_Phys_Base01 = 0xC,
	BONE_LeftArm_Phys_01 = 0xD,
	BONE_LeftElbowRoll = 0xE,
	BONE_LeftForeArm = 0xF,
	BONE_LeftHand = 0x10,
	BONE_LeftHandRing0 = 0x11,
	BONE_LeftHandRing1 = 0x12,
	BONE_LeftHandRing2 = 0x13,
	BONE_LeftHandRing3 = 0x14,
	BONE_LeftHandRing4 = 0x15,
	BONE_LeftHandPinky0 = 0x16,
	BONE_LeftHandPinky1 = 0x17,
	BONE_LeftHandPinky2 = 0x18,
	BONE_LeftHandPinky3 = 0x19,
	BONE_LeftHandPinky4 = 0x1A,
	BONE_LeftHandIndex0 = 0x1B,
	BONE_LeftHandIndex1 = 0x1C,
	BONE_LeftHandIndex2 = 0x1D,
	BONE_LeftHandIndex3 = 0x1E,
	BONE_LeftHandIndex4 = 0x1F,
	BONE_LeftHandThumb1 = 0x20,
	BONE_LeftHandThumb2 = 0x21,
	BONE_LeftHandThumb3 = 0x22,
	BONE_LeftHandThumb4 = 0x23,
	BONE_LeftHandMiddle0 = 0x24,
	BONE_LeftHandMiddle1 = 0x25,
	BONE_LeftHandMiddle2 = 0x26,
	BONE_LeftHandMiddle3 = 0x27,
	BONE_LeftHandMiddle4 = 0x28,
	BONE_LeftHand_Phys_Base01 = 0x29,
	BONE_LeftHand_Phys_01 = 0x2A,
	BONE_LeftHandAttach = 0x2B,
	BONE_LeftHandRollAim = 0x2C,
	BONE_LeftForeArmRoll = 0x2D,
	BONE_LeftForeArmRoll1 = 0x2E,
	BONE_LeftForeArmRoll3_Phys = 0x2F,
	BONE_LeftForeArmRoll2 = 0x30,
	BONE_LeftForeArmRoll2_Phys = 0x31,
	BONE_LeftArmRoll1 = 0x32,
	BONE_Neck = 0x33,
	BONE_Neck1 = 0x34,
	BONE_Head = 0x35,
	BONE_HeadEnd = 0x36,
	BONE_Head_Phys = 0x37,
	BONE_Head_Prop = 0x38,
	BONE_Head_Prop_Child_01 = 0x39,
	BONE_Head_Prop_Child_02 = 0x3A,
	BONE_Head_Prop_Child_03 = 0x3B,
	BONE_Head_Prop_Child_04 = 0x3C,
	BONE_Head_Phys_Base01 = 0x3D,
	BONE_Head_Phys_01 = 0x3E,
	BONE_FACIAL_C_FacialRoot = 0x3F,
	BONE_FACIAL_LOD1_C_Forehead = 0x40,
	BONE_FACIAL_LOD1_L_ForeheadIn = 0x41,
	BONE_FACIAL_LOD1_R_ForeheadIn = 0x42,
	BONE_FACIAL_LOD1_L_ForeheadMid = 0x43,
	BONE_FACIAL_LOD1_R_ForeheadMid = 0x44,
	BONE_FACIAL_LOD1_L_ForeheadOut = 0x45,
	BONE_FACIAL_LOD1_R_ForeheadOut = 0x46,
	BONE_FACIAL_LOD1_L_EyesackUpper = 0x47,
	BONE_FACIAL_LOD1_R_EyesackUpper = 0x48,
	BONE_FACIAL_LOD1_L_EyelidUpperFurrow = 0x49,
	BONE_FACIAL_LOD1_R_EyelidUpperFurrow = 0x4A,
	BONE_FACIAL_LOD1_L_EyelidUpper = 0x4B,
	BONE_FACIAL_LOD1_R_EyelidUpper = 0x4C,
	BONE_FACIAL_LOD1_L_Eyeball = 0x4D,
	BONE_FACIAL_LOD1_L_Pupil = 0x4E,
	BONE_FACIAL_LOD1_R_Eyeball = 0x4F,
	BONE_FACIAL_LOD1_R_Pupil = 0x50,
	BONE_FACIAL_LOD1_L_EyelidLower = 0x51,
	BONE_FACIAL_LOD1_R_EyelidLower = 0x52,
	BONE_FACIAL_LOD1_L_EyesackLower = 0x53,
	BONE_FACIAL_LOD1_R_EyesackLower = 0x54,
	BONE_FACIAL_LOD1_L_CheekInner = 0x55,
	BONE_FACIAL_LOD1_R_CheekInner = 0x56,
	BONE_FACIAL_LOD1_L_CheekOuter = 0x57,
	BONE_FACIAL_LOD1_R_CheekOuter = 0x58,
	BONE_FACIAL_LOD1_C_NoseBridge = 0x59,
	BONE_FACIAL_LOD1_L_NasolabialBulge = 0x5A,
	BONE_FACIAL_LOD1_R_NasolabialBulge = 0x5B,
	BONE_FACIAL_LOD1_L_NasolabialFurrow = 0x5C,
	BONE_FACIAL_LOD1_R_NasolabialFurrow = 0x5D,
	BONE_FACIAL_LOD1_L_CheekLower = 0x5E,
	BONE_FACIAL_LOD1_R_CheekLower = 0x5F,
	BONE_FACIAL_LOD1_L_Ear = 0x60,
	BONE_FACIAL_LOD1_R_Ear = 0x61,
	BONE_FACIAL_LOD1_C_Nose = 0x62,
	BONE_FACIAL_LOD1_C_NoseLower = 0x63,
	BONE_FACIAL_LOD1_L_Nostril = 0x64,
	BONE_FACIAL_LOD1_R_Nostril = 0x65,
	BONE_FACIAL_LOD1_C_Mouth = 0x66,
	BONE_FACIAL_LOD1_C_LipUpper = 0x67,
	BONE_FACIAL_LOD1_C_LipUpperInner = 0x68,
	BONE_FACIAL_LOD1_L_LipUpper = 0x69,
	BONE_FACIAL_LOD1_L_LipUpperInner = 0x6A,
	BONE_FACIAL_LOD1_R_LipUpper = 0x6B,
	BONE_FACIAL_LOD1_R_LipUpperInner = 0x6C,
	BONE_FACIAL_LOD1_L_LipUpperOuter = 0x6D,
	BONE_FACIAL_LOD1_L_LipUpperOuterInner = 0x6E,
	BONE_FACIAL_LOD1_R_LipUpperOuter = 0x6F,
	BONE_FACIAL_LOD1_R_LipUpperOuterInner = 0x70,
	BONE_FACIAL_LOD1_L_LipCorner = 0x71,
	BONE_FACIAL_LOD1_L_LipCornerInner = 0x72,
	BONE_FACIAL_LOD1_R_LipCorner = 0x73,
	BONE_FACIAL_LOD1_R_LipCornerInner = 0x74,
	BONE_FACIAL_LOD1_C_LipLower = 0x75,
	BONE_FACIAL_LOD1_C_LipLowerInner = 0x76,
	BONE_FACIAL_LOD1_L_LipLower = 0x77,
	BONE_FACIAL_LOD1_L_LipLowerInner = 0x78,
	BONE_FACIAL_LOD1_R_LipLower = 0x79,
	BONE_FACIAL_LOD1_R_LipLowerInner = 0x7A,
	BONE_FACIAL_LOD1_L_LipLowerOuter = 0x7B,
	BONE_FACIAL_LOD1_L_LipLowerOuterInner = 0x7C,
	BONE_FACIAL_LOD1_R_LipLowerOuter = 0x7D,
	BONE_FACIAL_LOD1_R_LipLowerOuterInner = 0x7E,
	BONE_FACIAL_LOD1_C_Jaw = 0x7F,
	BONE_FACIAL_LOD1_C_Chin = 0x80,
	BONE_FACIAL_LOD1_L_ChinSide = 0x81,
	BONE_FACIAL_LOD1_R_ChinSide = 0x82,
	BONE_FACIAL_LOD1_C_Tongue1 = 0x83,
	BONE_FACIAL_LOD1_C_Tongue2 = 0x84,
	BONE_FACIAL_LOD1_C_Tongue3 = 0x85,
	BONE_FACIAL_LOD1_C_Tongue4 = 0x86,
	BONE_FACIAL_LOD1_L_Masseter = 0x87,
	BONE_FACIAL_LOD1_R_Masseter = 0x88,
	BONE_FACIAL_LOD1_C_UnderChin = 0x89,
	BONE_FACIAL_LOD1_L_UnderChin = 0x8A,
	BONE_FACIAL_LOD1_R_UnderChin = 0x8B,
	BONE_FACIAL_C_Neck2Root = 0x8C,
	BONE_FACIAL_LOD1_C_AdamsApple = 0x8D,
	BONE_Wep2_Root = 0x8E,
	BONE_Spine2_Phys = 0x8F,
	BONE_Spine2_Phys_Ext_Base01 = 0x90,
	BONE_Spine2_Phys_Ext_01 = 0x91,
	BONE_Spine2_Phys_Ext_Base02 = 0x92,
	BONE_Spine2_Phys_Ext_02 = 0x93,
	BONE_Spine2_Phys_Ext_Base03 = 0x94,
	BONE_Spine2_Phys_Ext_03 = 0x95,
	BONE_Spine2_Phys_Ext_Base04 = 0x96,
	BONE_Spine2_Phys_Ext_04 = 0x97,
	BONE_scarf_07 = 0x98,
	BONE_scarf_01 = 0x99,
	BONE_scarf_02 = 0x9A,
	BONE_scarf_03 = 0x9B,
	BONE_scarf_04 = 0x9C,
	BONE_scarf_08 = 0x9D,
	BONE_scarf_05 = 0x9E,
	BONE_scarf_06 = 0x9F,
	BONE_LeftDeltoidBulge = 0xA0,
	BONE_LeftArmpit = 0xA1,
	BONE_LeftArmpitLow = 0xA2,
	BONE_RightShoulder = 0xA3,
	BONE_RightShoulder_Phys = 0xA4,
	BONE_RightArm = 0xA5,
	BONE_RightArmRoll = 0xA6,
	BONE_RightArm_Phys_Base01 = 0xA7,
	BONE_RightArm_Phys_01 = 0xA8,
	BONE_RightElbowRoll = 0xA9,
	BONE_RightForeArm = 0xAA,
	BONE_RightHand = 0xAB,
	BONE_RightHandRing0 = 0xAC,
	BONE_RightHandRing1 = 0xAD,
	BONE_RightHandRing2 = 0xAE,
	BONE_RightHandRing3 = 0xAF,
	BONE_RightHandRing4 = 0xB0,
	BONE_RightHandPinky0 = 0xB1,
	BONE_RightHandPinky1 = 0xB2,
	BONE_RightHandPinky2 = 0xB3,
	BONE_RightHandPinky3 = 0xB4,
	BONE_RightHandPinky4 = 0xB5,
	BONE_RightHandIndex0 = 0xB6,
	BONE_RightHandIndex1 = 0xB7,
	BONE_RightHandIndex2 = 0xB8,
	BONE_RightHandIndex3 = 0xB9,
	BONE_RightHandIndex4 = 0xBA,
	BONE_RightHandThumb1 = 0xBB,
	BONE_RightHandThumb2 = 0xBC,
	BONE_RightHandThumb3 = 0xBD,
	BONE_RightHandThumb4 = 0xBE,
	BONE_RightHandMiddle0 = 0xBF,
	BONE_RightHandMiddle1 = 0xC0,
	BONE_RightHandMiddle2 = 0xC1,
	BONE_RightHandMiddle3 = 0xC2,
	BONE_RightHandMiddle4 = 0xC3,
	BONE_RightHand_Phys_Base01 = 0xC4,
	BONE_RightHand_Phys_01 = 0xC5,
	BONE_RightHandAttach = 0xC6,
	BONE_RightHandRollAim = 0xC7,
	BONE_RightForeArmRoll = 0xC8,
	BONE_RightForeArmRoll1 = 0xC9,
	BONE_RightForeArmRoll3_Phys = 0xCA,
	BONE_RightForeArmRoll2 = 0xCB,
	BONE_RightForeArmRoll2_Phys = 0xCC,
	BONE_RightArmRoll1 = 0xCD,
	BONE_RightDeltoidBulge = 0xCE,
	BONE_RightArmpit = 0xCF,
	BONE_RightArmpitLow = 0xD0,
	BONE_Wep_Root = 0xD1,
	BONE_Wep_Trigger = 0xD2,
	BONE_Wep_Slide = 0xD3,
	BONE_Wep_Grenade1 = 0xD4,
	BONE_Wep_Grenade2 = 0xD5,
	BONE_Wep_Mag = 0xD6,
	BONE_Wep_Mag_Ammo = 0xD7,
	BONE_Wep_Mag_Extra1 = 0xD8,
	BONE_Wep_Scope1 = 0xD9,
	BONE_Wep_Scope2 = 0xDA,
	BONE_Wep_Belt1 = 0xDB,
	BONE_Wep_Belt2 = 0xDC,
	BONE_Wep_Belt3 = 0xDD,
	BONE_Wep_Belt4 = 0xDE,
	BONE_Wep_Belt5 = 0xDF,
	BONE_Wep_Belt6 = 0xE0,
	BONE_Wep_Belt7 = 0xE1,
	BONE_Wep_Belt8 = 0xE2,
	BONE_Wep_Belt9 = 0xE3,
	BONE_Wep_Belt10 = 0xE4,
	BONE_Wep_Bipod1 = 0xE5,
	BONE_Wep_Bipod2 = 0xE6,
	BONE_Wep_Bipod3 = 0xE7,
	BONE_IK_Joint_LeftHand = 0xE8,
	BONE_IK_Joint_RightHand = 0xE9,
	BONE_Wep_Physic1 = 0xEA,
	BONE_Wep_Physic2 = 0xEB,
	BONE_Wep_Physic3 = 0xEC,
	BONE_Wep_Physic4 = 0xED,
	BONE_Wep_Physic5 = 0xEE,
	BONE_Wep_Extra1 = 0xEF,
	BONE_Wep_Extra2 = 0xF0,
	BONE_Wep_Extra3 = 0xF1,
	BONE_Wep_Extra4 = 0xF2,
	BONE_Wep_Extra5 = 0xF3,
	BONE_Wep_FX = 0xF4,
	BONE_Wep_Aim = 0xF5,
	BONE_Spine1_Phys = 0xF6,
	BONE_Spine1_Phys_Ext_Base01 = 0xF7,
	BONE_Spine1_Phys_Ext_01 = 0xF8,
	BONE_Spine1_Phys_Ext_Base02 = 0xF9,
	BONE_Spine1_Phys_Ext_02 = 0xFA,
	BONE_Spine1_Phys_Ext_Base03 = 0xFB,
	BONE_Spine1_Phys_Ext_03 = 0xFC,
	BONE_Spine1_Phys_Ext_Base04 = 0xFD,
	BONE_Spine1_Phys_Ext_04 = 0xFE,
	BONE_Spine_Phys = 0xFF,
	BONE_Spine_Phys_Ext_Base01 = 0x100,
	BONE_Spine_Phys_Ext_01 = 0x101,
	BONE_Spine_Phys_Ext_Base02 = 0x102,
	BONE_Spine_Phys_Ext_02 = 0x103,
	BONE_Spine_Phys_Ext_Base03 = 0x104,
	BONE_Spine_Phys_Ext_03 = 0x105,
	BONE_Spine_Phys_Ext_Base04 = 0x106,
	BONE_Spine_Phys_Ext_04 = 0x107,
	BONE_Spine_Phys_Weapon_Base01 = 0x108,
	BONE_Spine_Phys_Weapon_01 = 0x109,
	BONE_Hips_Phys = 0x10A,
	BONE_Hips_Phys_Ext_Base01 = 0x10B,
	BONE_Hips_Phys_Ext_01 = 0x10C,
	BONE_Hips_Phys_Ext_Base02 = 0x10D,
	BONE_Hips_Phys_Ext_02 = 0x10E,
	BONE_Hips_Phys_Ext_Base03 = 0x10F,
	BONE_Hips_Phys_Ext_03 = 0x110,
	BONE_Hips_Phys_Ext_Base04 = 0x111,
	BONE_Hips_Phys_Ext_04 = 0x112,
	BONE_LeftUpLeg = 0x113,
	BONE_LeftLeg = 0x114,
	BONE_LeftFoot = 0x115,
	BONE_LeftToeBase = 0x116,
	BONE_LeftToe = 0x117,
	BONE_LeftLeg_Phys_Base01 = 0x118,
	BONE_LeftLeg_Phys_01 = 0x119,
	BONE_LeftKneeLow = 0x11A,
	BONE_LeftUpLeg_Phys_Base01 = 0x11B,
	BONE_LeftUpLeg_Phys_01 = 0x11C,
	BONE_LeftKneeUp = 0x11D,
	BONE_LeftUpLegRoll = 0x11E,
	BONE_LeftKneeRoll = 0x11F,
	BONE_LeftHipsRoll = 0x120,
	BONE_RightUpLeg = 0x121,
	BONE_RightLeg = 0x122,
	BONE_RightFoot = 0x123,
	BONE_RightToeBase = 0x124,
	BONE_RightToe = 0x125,
	BONE_RightLeg_Phys_Base01 = 0x126,
	BONE_RightLeg_Phys_01 = 0x127,
	BONE_RightKneeLow = 0x128,
	BONE_RightUpLeg_Phys_Base01 = 0x129,
	BONE_RightUpLeg_Phys_01 = 0x12A,
	BONE_RightKneeUp = 0x12B,
	BONE_RightUpLegRoll = 0x12C,
	BONE_RightKneeRoll = 0x12D,
	BONE_RightHipsRoll = 0x12E,
	BONE_CameraBase = 0x12F,
	BONE_CameraJoint = 0x130,
	BONE_Connect = 0x131,
	BONE_ConnectEnd = 0x132,
	BONE_LeftFootPhaseEnd = 0x133,
	BONE_RightFootPhaseEnd = 0x134,
	BONE_FacePosesAnimation = 0x135
};

#include "ClientGameContext.hpp"
#include "GameRenderer.hpp"
#include "RenderView.hpp"
#include "DXRenderer.hpp"
#include "Level.hpp"
#include "OnlineManager.hpp"
#include "ClientPlayerManager.hpp"
#include "ClientPlayer.hpp"
#include "ClientSoldierEntity.hpp"
#include "ClientSoldierHealthComponent.hpp"
#include "ClientSoldierWeaponsComponent.hpp"
#include "ClientAimEntity.hpp"
#include "ClientSoldierWeapon.hpp"
#include "ClientSoldierPrediction.hpp"
#include "SoldierWeaponData.hpp"
#include "WeaponFiringData.hpp"
#include "SoldierAimingSimulationData.hpp"
#include "SoldierWeaponBlueprint.hpp"
#include "ClientWeapon.hpp"
#include "WeaponModifier.hpp"
#include "FiringFunctionData.hpp"
#include "BulletEntityData.hpp"
#include "WeaponFiring.hpp"
#include "ClientActiveWeaponHandler.hpp"
#include "ClientAnimatedSoldierWeaponHandler.hpp"
#include "ClientSoldierAimingSimulation.hpp"
#include "FpsAimer.hpp"
#include "Screen.hpp"
#include "Color32.hpp"
#include "DebugRenderer2.hpp"