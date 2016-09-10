#pragma once

namespace fb
{
	class ClientSoldierPrediction
	{
	public:
		char _0x0000[ 48 ];
		D3DXVECTOR3 m_Position; //0x0030 
		char _0x003C[ 20 ];
		D3DXVECTOR3 m_Velocity; //0x0050 
		char _0x005C[ 32 ];
		BYTE m_Pose; //0x007C 
		char _0x007D[ 3 ];
		BYTE m_ChangingToPose; //0x0080 
		char _0x0081[ 23 ];
		__int32 Event; //0x0098 
		__int32 PlayerState; //0x009C 
		char _0x00A0[ 32 ];

	};//Size=0x00C0
}