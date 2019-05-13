#include "SFML/Graphics.hpp"
#include "BattleScene.h"
#include "BattleEngine.h"
#include "Animation.h"
#include <string.h>
#include <vector>
using namespace std;
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
		sf::Clock updateClock;
		sf::Clock frameClock;
		int maxUpdates = 5;
		float updateRate = 1.0f / 20;

		updateClock.restart();

		//Load bg
		sf::Texture texture;
		if (!texture.loadFromFile("images/battlebg.png")) {
			//return EXIT_FAILURE;
		}
		battlebg.setTexture(texture);


		bEngine.startBattle(1, 2, gameEngine);
		startPlayerSprite();
		startOpponentSprite();

		while (gameEngine->gameWindow.isOpen()) {

			sf::Int32 updateNext = updateClock.getElapsedTime().asMilliseconds();
			int updates = 0;

			sf::Event event;
			while (gameEngine->gameWindow.pollEvent(event))
			{

				// Close window: exit
				if (event.type == sf::Event::Closed) {
					gameEngine->gameWindow.close();
				}

				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up)) {
					bEngine.move(sf::Keyboard::Up);
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left)) {
					bEngine.move(sf::Keyboard::Left);
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down)) {
					bEngine.move(sf::Keyboard::Down);
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right)) {
					bEngine.move(sf::Keyboard::Right);
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::S)) {
					bEngine.weakAttack();
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D)) {
					bEngine.strongAttack();
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::LShift)) {
					bEngine.physicalAttack();	
				}
			}
			
			sf::Int32 updateTime = updateClock.getElapsedTime().asMilliseconds();

			//while ((updateTime - updateNext) >= updateRate && updates++ < maxUpdates) {
				bEngine.update();
				//updateNext += updateRate;
			//}

		
			gameEngine->gameWindow.clear();
			drawField();
			
			drawCreatures();
			drawAttacks();

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

		setSpriteset(true);
		playerSprite.setTexture(playerSpriteset);
		playerAnimation.update();

		//Change origin to bottom center
		playerSprite.setOrigin(playerSprite.getGlobalBounds().width/2, playerSprite.getGlobalBounds().height);
		shadow.setOrigin(shadow.getGlobalBounds().width/2, shadow.getGlobalBounds().height);

		playerSprite.setPosition(bEngine.getPlayer().getScreenPosition());
		shadow.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y+6);
		gameEngine->gameWindow.draw(shadow);
		gameEngine->gameWindow.draw(playerSprite);

		drawPlayerHP();

		//Draw opponent shadow
		sf::Texture oshadowT;
		if (!oshadowT.loadFromFile("images/shadow.png")) {
			//return EXIT_FAILURE;
		}
		sf::Sprite oshadow;
		oshadow.setTexture(oshadowT);

		setSpriteset(false);
		opponentSprite.setTexture(opponentSpriteset);
		

		//Change origin to bottom center
		opponentSprite.setOrigin(opponentSprite.getGlobalBounds().width/2, opponentSprite.getGlobalBounds().height);
		oshadow.setOrigin(oshadow.getGlobalBounds().width/2, oshadow.getGlobalBounds().height);
		opponentAnimation.update();

		//Set position
		opponentSprite.setPosition(bEngine.getOpponent().getScreenPosition());
		oshadow.setPosition(opponentSprite.getPosition().x, opponentSprite.getPosition().y + 6);
		gameEngine->gameWindow.draw(oshadow);
		gameEngine->gameWindow.draw(opponentSprite);

		drawOpponentHP();
	}

	void BattleScene::startPlayerSprite() {
		//Draw player
		int playerId = bEngine.getPlayer().getSpecies();
		string filepath = "images/creatures/" + std::to_string(playerId) + "_stand.png";

		
		if (!playerSpriteset.loadFromFile(filepath)) {
			//return EXIT_FAILURE;
		}

		playerSprite.setTexture(playerSpriteset);
		playerAnimation.setSprite(&playerSprite);
	}

	void BattleScene::startOpponentSprite() {
		//Draw opponent
		int opponentId = bEngine.getOpponent().getSpecies();

		ostate = "stand";

		string ofilepath = "images/creatures/" + std::to_string(opponentId) + "_stand.png";

		if (!opponentSpriteset.loadFromFile(ofilepath)) {
			//return EXIT_FAILURE;
		}

		//Flip sprite
		opponentSprite.scale(-1.f, 1.f);

		opponentSprite.setTexture(opponentSpriteset);
		opponentAnimation.setSprite(&opponentSprite);
	}


	void BattleScene::drawPlayerHP() {
		sf::Texture hpGaugeT;
		if (!hpGaugeT.loadFromFile("images/hpbar.png")) {
			//return EXIT_FAILURE;
		}
		sf::Sprite hpGauge;
		hpGauge.setTexture(hpGaugeT);
		hpGauge.setPosition(playerSprite.getPosition().x - 13, playerSprite.getPosition().y + 10);// - playerSprite.getGlobalBounds().height - 10);

		float percent = bEngine.getPlayer().getHPPercentage();
		string barname = "hpgreen";
		if (percent <= 0.25) {
			barname = "hpred";
		}
		else if (percent <= 0.5) {
			barname = "hpyellow";
		}
		sf::Texture hpBarT;
		if (!hpBarT.loadFromFile("images/"+ barname+".png")) {
			//return EXIT_FAILURE;
		}
		sf::Sprite hpBar;
		hpBar.setTexture(hpBarT);
		hpBar.setTextureRect(sf::IntRect(0,0, hpBarT.getSize().x*percent,hpBarT.getSize().y));
		hpBar.setPosition(hpGauge.getPosition().x+1, hpGauge.getPosition().y+1);

		gameEngine->gameWindow.draw(hpGauge);
		gameEngine->gameWindow.draw(hpBar);
	}

	void BattleScene::drawOpponentHP() {
		sf::Texture hpGaugeT;
		if (!hpGaugeT.loadFromFile("images/hpbar.png")) {
			//return EXIT_FAILURE;
		}
		sf::Sprite hpGauge;
		hpGauge.setTexture(hpGaugeT);
		hpGauge.setPosition(opponentSprite.getPosition().x - 13, opponentSprite.getPosition().y + 10);// -opponentSprite.getGlobalBounds().height - 10);

		float percent = bEngine.getOpponent().getHPPercentage();
		string barname = "hpgreen";
		if (percent <= 0.25) {
			barname = "hpred";
		}
		else if (percent <= 0.5) {
			barname = "hpyellow";
		}
		sf::Texture hpBarT;
		if (!hpBarT.loadFromFile("images/" + barname + ".png")) {
			//return EXIT_FAILURE;
		}
		sf::Sprite hpBar;
		hpBar.setTexture(hpBarT);
		hpBar.setTextureRect(sf::IntRect(0, 0, hpBarT.getSize().x*percent, hpBarT.getSize().y));
		hpBar.setPosition(hpGauge.getPosition().x + 1, hpGauge.getPosition().y + 1);

		gameEngine->gameWindow.draw(hpGauge);
		gameEngine->gameWindow.draw(hpBar);
	}

	void BattleScene::setSpriteset(bool isPlayer) {
		if (isPlayer) {
			string pstateOld = pstate;
			double speed = 0.5;
			bool repeat = true;
			int playerId = bEngine.getPlayer().getSpecies();

			if (bEngine.getPlayer().isStunned) {
				pstate = "stun";
				speed = 0.2;
			}
			else if (bEngine.getPlayer().isFainted) {
				pstate = "faint";
			}
			else if (bEngine.getPlayer().isAttacking) {
				pstate = "attack";
				//speed = 1;
				speed = 0.5;
				repeat = false;
			}
			else {
				pstate = "stand";
			}

			if (pstate.compare(pstateOld) != 0) {
				string pfilepath = "images/creatures/" + std::to_string(playerId) + "_" + pstate + ".png";
				if (!playerSpriteset.loadFromFile(pfilepath)) {
					//return EXIT_FAILURE;
				}
				playerSprite.setTexture(playerSpriteset);
				playerAnimation.reset(speed,repeat);
			}
		}
		else{
			string ostateOld = ostate;
			double speed = 0.5;
			int opponentId = bEngine.getOpponent().getSpecies();

			if (bEngine.getOpponent().isStunned) {
				ostate = "stun";
				speed = 0.2;
			}
			else if (bEngine.getOpponent().isFainted) {
				ostate = "faint";
			}
			else {
				ostate = "stand";
			}

			if (ostate.compare(ostateOld) != 0) {
				string ofilepath = "images/creatures/" + std::to_string(opponentId) + "_" + ostate + ".png";
				if (!opponentSpriteset.loadFromFile(ofilepath)) {
					//return EXIT_FAILURE;
				}
				opponentSprite.setTexture(opponentSpriteset);
				opponentAnimation.reset(speed);
			}
		}

	}

	void BattleScene::drawAttacks() {
		bEngine.drawAttacks();
	}

}

