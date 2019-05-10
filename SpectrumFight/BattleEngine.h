#include "Creature.h"
#include "FieldTile.h"
#include <array>
using namespace std;
#pragma once

namespace Spectrum {
	class BattleEngine
	{
	public:
		BattleEngine();
		~BattleEngine();
		void startBattle(int, int);
		void move(sf::Keyboard::Key);
		void weakAttack();
		void strongAttack();
		void physicalAttack();
		Creature getPlayer();
		Creature getOpponent();
		void update();

		Creature player;
		Creature opponent;

		//vector< vector <FieldTile> > field;
		std::array<std::array<FieldTile, 3>, 6> field;
	};
}


