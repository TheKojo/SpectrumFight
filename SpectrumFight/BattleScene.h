#include "GameScene.h"
#include "GameEngine.h"
#include "BattleEngine.h"
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

		GameEngine* gameEngine;
		BattleEngine bEngine;
		sf::Sprite battlebg;
	};
}


