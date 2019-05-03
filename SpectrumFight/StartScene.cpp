
#include "SFML/Graphics.hpp"
#include "StartScene.h"
#include "BattleScene.h"


namespace Spectrum {

	StartScene::StartScene(GameEngine* engine) : 
		gameEngine(engine)
	{
		
	}

	StartScene::~StartScene()
	{
	}

	void StartScene::main() {
		//Load start menu graphics
		sf::Texture texture;
		if (!texture.loadFromFile("images/startbg.png")) {
			//return EXIT_FAILURE;
		}
		startbg.setTexture(texture);

		// Create a graphical text to display
		sf::Font font;
		if (!font.loadFromFile("fonts/pkmnfl.ttf")) {
			//return EXIT_FAILURE;
		}
		text.setString("Press Enter");
		text.setFont(font);
		text.setCharacterSize(30);
		int screenWidth = gameEngine->gameWindow.getSize().x;
		int screenHeight = gameEngine->gameWindow.getSize().y;
		text.setPosition((screenWidth - text.getGlobalBounds().width) / 2.f, screenHeight / 2.f);

		bool started = false;
		while (gameEngine->gameWindow.isOpen()) {
			sf::Event event;
			while (gameEngine->gameWindow.pollEvent(event))
			{
				// Close window: exit
				if (event.type == sf::Event::Closed) {
					gameEngine->gameWindow.close();
				}

				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter)) {
					BattleScene bscene(gameEngine);
					bscene.main();
				}
			}
			if (!started) {
				draw();
				started = true;
			}

		}
	}

	void StartScene::draw() {
		gameEngine->gameWindow.clear();
		gameEngine->gameWindow.draw(startbg);
		gameEngine->gameWindow.draw(text);
		gameEngine->gameWindow.display();
	}
}

