#include "BattleAI.h"
#include <stdlib.h>

namespace Spectrum {
	BattleAI::BattleAI()
	{
		moveCounter = 0;
	}


	BattleAI::~BattleAI()
	{
	}

	void BattleAI::setAI(AIType newAI) {
		aiType = newAI;
		aiSpeed = 1000;
	}

	int BattleAI::makeMove() {
		int moveDir = 0;
		moveCounter += 1;
		if (moveCounter >= aiSpeed) {
			moveDir = rand() % 4 + 1;
			moveCounter = 0;
		}
		return moveDir;
		/*switch (moveDir) {
			case 0:
				return Creature::Up;
			case 1:
				return Creature::Left;
			case 2:
				return Creature::Right;
			case 3:
				return Creature::Down;
		}*/
	}
}
