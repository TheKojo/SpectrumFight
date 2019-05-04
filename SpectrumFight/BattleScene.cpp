
#include "SFML/Graphics.hpp"
#include "BattleScene.h"
#include "BattleEngine.h"
#include <string.h>
using std::string;


namespace Spectrum {
	BattleScene::BattleScene(GameEngine* engine) :
		gameEngine(engine)
	{
	}


	BattleScene::~BattleScene()
	{
	}

	void BattleScene::main() {
		//Load start menu graphics
		sf::Texture texture;
		if (!texture.loadFromFile("images/battlebg.png")) {
			//return EXIT_FAILURE;
		}
		battlebg.setTexture(texture);


		bEngine.startBattle(1, 2);

		while (gameEngine->gameWindow.isOpen()) {
			sf::Event event;
			while (gameEngine->gameWindow.pollEvent(event))
			{

				// Close window: exit
				if (event.type == sf::Event::Closed) {
					gameEngine->gameWindow.close();
				}

				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::W)) {
					bEngine.move(sf::Keyboard::W);
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A)) {
					bEngine.move(sf::Keyboard::A);
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::S)) {
					bEngine.move(sf::Keyboard::S);
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D)) {
					bEngine.move(sf::Keyboard::D);
				}
			}

			gameEngine->gameWindow.clear();
			drawField();
			drawCreatures();
			gameEngine->gameWindow.display();
		}



	}

	void BattleScene::drawField() {
		gameEngine->gameWindow.draw(battlebg);
	}

	void BattleScene::drawCreatures() {

		//Draw player shadow
		sf::Texture shadowT;
		if (!shadowT.loadFromFile("images/shadow.png")) {
			//return EXIT_FAILURE;
		}
		sf::Sprite shadow;
		shadow.setTexture(shadowT);

		//Draw player
		int playerId = bEngine.getPlayer().getId();
		string filepath = "images/creatures/" + std::to_string(playerId) + ".png";

		sf::Texture playerSpriteset;
		if (!playerSpriteset.loadFromFile(filepath)) {
			//return EXIT_FAILURE;
		}

		sf::Sprite playerSprite;
		playerSprite.setTexture(playerSpriteset);

		//Change origin to bottom center
		playerSprite.setOrigin(playerSprite.getGlobalBounds().width/2, playerSprite.getGlobalBounds().height);
		shadow.setOrigin(shadow.getGlobalBounds().width/2, shadow.getGlobalBounds().height);

		playerSprite.setPosition(bEngine.getPlayer().getScreenPosition());
		shadow.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y+6);
		gameEngine->gameWindow.draw(shadow);
		gameEngine->gameWindow.draw(playerSprite);

	

		//Draw opponent shadow
		sf::Texture oshadowT;
		if (!oshadowT.loadFromFile("images/shadow.png")) {
			//return EXIT_FAILURE;
		}
		sf::Sprite oshadow;
		oshadow.setTexture(oshadowT);

		//Draw opponent
		int opponentId = bEngine.getOpponent().getId();
		string ofilepath = "images/creatures/" + std::to_string(opponentId) + ".png";

		sf::Texture opponentSpriteset;
		if (!opponentSpriteset.loadFromFile(ofilepath)) {
			//return EXIT_FAILURE;
		}

		sf::Sprite opponentSprite;
		opponentSprite.setTexture(opponentSpriteset);

		//Flip the sprite
		opponentSprite.scale(-1.f, 1.f);
		opponentSprite.setOrigin(opponentSprite.getGlobalBounds().width/2, opponentSprite.getGlobalBounds().height);
		oshadow.setOrigin(oshadow.getGlobalBounds().width/2, oshadow.getGlobalBounds().height);

		//Set position
		opponentSprite.setPosition(bEngine.getOpponent().getScreenPosition());
		oshadow.setPosition(opponentSprite.getPosition().x, opponentSprite.getPosition().y + 6);
		gameEngine->gameWindow.draw(oshadow);
		gameEngine->gameWindow.draw(opponentSprite);

	}
}

