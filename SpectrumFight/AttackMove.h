#pragma once
#include <array>
#include <vector>
#include "Attack.h"
#include "SFML/Graphics.hpp"
#include "GameEngine.h"
#include "SFML/Graphics.hpp"
#include "Animation.h"
using namespace std;

namespace Spectrum {

	class Creature;

	//class Attack;

	class FieldTile;

	class AttackMove
	{
	public:
		AttackMove();
		~AttackMove();

		void init(Creature* creature, std::array<std::array<FieldTile, 3>, 6>* fieldArr, GameEngine* enginePointer);
		void update();
		void setDone();
		bool isDone();

		void drawMove();
		void startDrawMove();

		Attack physAttack;
		std::array<std::array<FieldTile, 3>, 6>* field;
		GameEngine* engine;

		int damage;
		int duration; //determines how long move lasts on tile
		int attackerDelay; //determines how long creature remains stationary after using move
		int stunDelay; //determines how long creature remains stunned after being hit by move

		bool dealtDamage;
		bool done;
		bool test;
		Creature* attacker;
		std::vector<sf::Vector2i> activePositions;

		sf::Sprite attackSprite;
		sf::Texture attackTexture;
		Animation attackAnim;
	};
}


