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
		const int screenWidth = 400;
		const int screenHeight = 225;
		gameWindow.create(sf::VideoMode(screenWidth, screenHeight), "Spectrum Fight");
		//gameWindow.setFramerateLimit(60);

		StartScene sscene(this);
		sscene.main();

	}

	sf::RenderWindow* GameEngine::getWindow() {
		return &gameWindow;
	}
}

