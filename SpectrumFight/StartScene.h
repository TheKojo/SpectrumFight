#include "GameScene.h"
#include "GameEngine.h"
#pragma once

namespace Spectrum {
	class StartScene //:
		//public GameScene
	{
	public:
		StartScene(GameEngine*);
		StartScene();
		~StartScene();

		void main();
		void draw();


		GameEngine* gameEngine;
		sf::Sprite startbg;
		sf::Text text;
	};


}


