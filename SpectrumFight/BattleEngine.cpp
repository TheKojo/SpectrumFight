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
		player.setId(playerId);
		player.setPosition(Creature::MiddleCenter);
		opponent.setId(opponentId);
		opponent.setPosition(Creature::oMiddleCenter);
	}

	void BattleEngine::move(sf::Keyboard::Key key) {
		switch (key) {
			case sf::Keyboard::W:
				player.moveUp();
				break;
			case sf::Keyboard::A:
				player.moveLeft();
				break;
			case sf::Keyboard::S:
				player.moveDown();
				break;
			case sf::Keyboard::D:
				player.moveRight();
				break;
		}
	}

	Creature BattleEngine::getPlayer() {
		return player;
	}

	Creature BattleEngine::getOpponent() {
		return opponent;
	}
}



