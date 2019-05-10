#include "SFML/Graphics.hpp"
#include "BattleEngine.h"
#include "Creature.h"
#include "FieldTile.h"

namespace Spectrum {
	BattleEngine::BattleEngine()
	{
	}


	BattleEngine::~BattleEngine()
	{
	}

	void BattleEngine::startBattle(int playerSpecies, int opponentSpecies) {

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				FieldTile tile;
				field[i][j] = tile;
			}
		}

		player.init(1, playerSpecies, true, &field);
		opponent.init(2, opponentSpecies, false, &field);
	}

	void BattleEngine::move(sf::Keyboard::Key key) {
		
		switch (key) {
			case sf::Keyboard::Up:
				player.move(Creature::Up);
				break;
			case sf::Keyboard::Left:
				player.move(Creature::Left);
				break;
			case sf::Keyboard::Down:
				player.move(Creature::Down);
				break;
			case sf::Keyboard::Right:
				player.move(Creature::Right);
				break;
		}
	}

	void BattleEngine::weakAttack() {

	}
	void BattleEngine::strongAttack() {

	}
	void BattleEngine::physicalAttack() {
		player.physicalAttack();

	}

	Creature BattleEngine::getPlayer() {
		return player;
	}

	Creature BattleEngine::getOpponent() {
		return opponent;
	}

	void BattleEngine::update() {
		player.update();
		opponent.makeMove();
		opponent.update();

		//Update field
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				field[i][j].update();
			}
		}
	}
}



