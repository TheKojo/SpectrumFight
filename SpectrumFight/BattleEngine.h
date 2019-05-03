#include "Creature.h"
#pragma once

namespace Spectrum {
	class BattleEngine
	{
	public:
		BattleEngine();
		~BattleEngine();
		void startBattle(int, int);
		void move(sf::Keyboard::Key);
		Creature getPlayer();
		Creature getOpponent();

		Creature player;
		Creature opponent;
	};
}


