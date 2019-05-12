#include "Creature.h"
#include "FieldTile.h"
#include <array>
#include "GameEngine.h"

using namespace std;
#pragma once

namespace Spectrum {
	
	//class GameEngine;

	class BattleEngine
	{
	public:
		BattleEngine();
		~BattleEngine();
		void startBattle(int, int, GameEngine*);
		void move(sf::Keyboard::Key);
		void weakAttack();
		void strongAttack();
		void physicalAttack();
		Creature getPlayer();
		Creature getOpponent();
		void update();
		void drawAttacks();

		Creature player;
		Creature opponent;
		GameEngine* engine;

		//vector< vector <FieldTile> > field;
		std::array<std::array<FieldTile, 3>, 6> field;
	};
}


