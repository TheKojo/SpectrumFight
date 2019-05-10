#pragma once
#include <array>
#include <vector>
#include "Attack.h"
#include "SFML/Graphics.hpp"
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

		void init(Creature* creature, std::array<std::array<FieldTile, 3>, 6>* fieldArr);
		void update();
		void setDone();
		bool isDone();

		Attack physAttack;
		std::array<std::array<FieldTile, 3>, 6>* field;

		bool dealtDamage;
		bool done;
		bool test;
		int creatureId;
		std::vector<sf::Vector2i> activePositions;
	};
}


