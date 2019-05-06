#include "GameScene.h"
#include "GameEngine.h"
#include "BattleEngine.h"
#include "Animation.h"
#pragma once

namespace Spectrum {
	class BattleScene

	{
	public:
		BattleScene(GameEngine*);
		BattleScene();
		~BattleScene();

		void main();
		void drawField();
		void drawCreatures();
		void startPlayerSprite();
		void startOpponentSprite();

		GameEngine* gameEngine;
		BattleEngine bEngine;
		sf::Sprite battlebg;

		sf::Sprite playerSprite;
		sf::Texture playerSpriteset;
		Animation playerAnimation;

		sf::Sprite opponentSprite;
		sf::Texture opponentSpriteset;
		Animation opponentAnimation;
	};
}


