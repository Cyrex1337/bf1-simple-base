#pragma once

namespace fb
{
	class ClientSoldierHealthComponent
	{
	public:
		char _0x0000[ 16 ];
		SoldierHealthComponentData* m_pBFSoldierHealthComponentData; //0x0010 [BFSoldierHealthComponentData]
		char _0x0018[ 8 ];
		float m_Health; //0x0020 
		float m_MaxHealth; //0x0024 
		char _0x0028[ 88 ];

	};//Size=0x0080
}