#include "GameEngine.h"
#include "StartScene.h"

namespace Spectrum {

	GameEngine::GameEngine()
	{
	}


	GameEngine::~GameEngine()
	{
	}

	void GameEngine::start() {
		const int screenWidth = 740;
		const int screenHeight = 480;
		gameWindow.create(sf::VideoMode(screenWidth, screenHeight), "SFight Window");

		StartScene sscene(this);
		sscene.main();

	}
}

