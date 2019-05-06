#include "SFML/Graphics.hpp"
#include "BattleEngine.h"
#include "Creature.h"

namespace Spectrum {
	BattleEngine::BattleEngine()
	{
	}


	BattleEngine::~BattleEngine()
	{
	}

	void BattleEngine::startBattle(int playerId, int opponentId) {
		player.setId(playerId, true);
		player.setPosition(Creature::MiddleCenter);
		opponent.setId(opponentId, false);
		opponent.setPosition(Creature::oMiddleCenter);
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

	Creature BattleEngine::getPlayer() {
		return player;
	}

	Creature BattleEngine::getOpponent() {
		return opponent;
	}

	void BattleEngine::update() {
		player.updatePosition();
		opponent.makeMove();
		opponent.updatePosition();
	}
}



