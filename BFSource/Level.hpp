#pragma once

namespace fb
{
	class Level
	{
	public:
		char _0x0000[ 24 ];
		LevelData* m_pLevelData; //0x0018 [LevelData]
		TeamEntityData** m_ppTeamEntityData; //0x0020 Smart[TeamEntityData]
		char* m_LevelName; //0x0028 
		char _0x0030[ 216 ];
		PhysicsManager* m_pPhysicsManager; //0x0108 [PhysicsManager]
		char _0x0110[ 816 ];

	};//Size=0x0440
}
