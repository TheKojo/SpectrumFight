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
		void drawPlayerHP();
		void drawOpponentHP();
		void setSpriteset(bool);

		void drawAttacks();

		GameEngine* gameEngine;
		BattleEngine bEngine;
		sf::Sprite battlebg;

		sf::Sprite playerSprite;
		sf::Texture playerSpriteset;
		Animation playerAnimation;
		string pstate;

		sf::Sprite opponentSprite;
		sf::Texture opponentSpriteset;
		Animation opponentAnimation;
		string ostate;


		sf::Sprite attackSprite;
		sf::Texture attackTexture;
		Animation attackAnim;

		bool drawAtk;
	};
}


