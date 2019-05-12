#pragma once
#include <string>
#include <array>
#include <vector>
#include "SFML/Graphics.hpp"
#include "BattleAI.h"
#include "AttackMove.h"
#include "Attack.h"
#include "GameEngine.h"


using namespace std;
using std::string;


namespace Spectrum {

	class FieldTile;

	class Creature
	{
	public:
		Creature();
		~Creature();
		GameEngine* engine;

		enum Movement {
			Up = 0,
			Left,
			Right,
			Down,
		};

		void init(int newId, int species, bool player, std::array<std::array<FieldTile, 3>, 6>* fieldArr, GameEngine* enginePointer);

		void setId(int, bool);
		int getId();
		int getSpecies();
		void move(Movement);
		void moveUp();
		void moveLeft();
		void moveRight();
		void moveDown();
		//void setPosition(FieldPosition);
		bool isMoving;
		bool isAttacking;
		bool isStunned;
		bool isFainted;
		sf::Vector2f getScreenPosition();
		sf::Vector2f tilePositions(sf::Vector2i);
		void updatePosition();
		void makeMove();
		void physicalAttack();

		float getHPPercentage();
		void reduceHP(int val);
		void damageCreature(int damageVal, int delayVal);
		void updateAttacks();
		void update();
		void drawAttacks();

		int id;
		int species;
		string name;
		float totalHP;
		float curHP;
		int speed; //lower values are faster
		Attack physAttack;

		std::array<std::array<FieldTile, 3>, 6>* field;

		sf::Vector2i position;
		sf::Vector2i oldPosition;
		sf::Vector2f oldCoord;
		sf::Vector2f finalCoord;
		sf::Vector2f curCoord;
		int moveTimer;
		int attackDelayTimer;
		int stunTimer;

		bool isPlayer;
		BattleAI AI;

		std::vector<AttackMove> activeAttacks;

	};
}


