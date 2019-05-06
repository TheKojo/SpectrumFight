
#pragma once

namespace Spectrum {
	class BattleAI
	{
	public:
		BattleAI();
		~BattleAI();

		enum AIType {
			Random = 0
		};

		AIType aiType;
		int aiSpeed; //lower makes moves for frequently
		int moveCounter;
		void setAI(AIType);
		int makeMove();
	};

}

