#include "SFML/Graphics.hpp"
#include "GameScene.h"
#include "GameEngine.h"

sf::RenderWindow window;

namespace Spectrum {
	GameScene::GameScene(GameEngine* engine) : 
		gameEngine(engine)
	{
		
	}


	GameScene::~GameScene()
	{
	}

	void GameScene::main() {

	}
}
