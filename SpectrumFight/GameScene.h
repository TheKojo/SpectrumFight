#pragma once
#include "GameEngine.h"

namespace Spectrum {
	class GameScene
	{
	public:
		GameScene();
		GameScene(GameEngine*);
		~GameScene();
		void main();
		void draw();

		GameEngine* gameEngine;
	};
}


