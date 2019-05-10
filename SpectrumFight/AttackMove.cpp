#include "AttackMove.h"
#include "Creature.h"
#include "FieldTile.h"
#include <array>
#include <vector>
using namespace std;


namespace Spectrum {
	AttackMove::AttackMove()
	{
		dealtDamage = false;
		done = false;
		test = false;
	}


	AttackMove::~AttackMove()
	{
	}

	void AttackMove::init(Creature* creature, std::array<std::array<FieldTile, 3>, 6>* fieldArr) {
		physAttack.init(10, 100, 100, creature->getId(), true, this);
		field = fieldArr;
		dealtDamage = false;
		done = false;
		test = false;
		creatureId = creature->getId();

		activePositions.push_back(sf::Vector2i(creature->position.x + 1, creature->position.y));
		activePositions.push_back(sf::Vector2i(creature->position.x + 2, creature->position.y));

		//put attack on field
		//range is 2 spaces horizontal of creature's position
		//(*field)[creature->position.x + 1][creature->position.y].setAttack(&physAttack);
		//(*field)[creature->position.x + 2][creature->position.y].setAttack(&physAttack);


	}

	void AttackMove::update() {
		//check if creature collision within range
		for (int i = 0; i < activePositions.size(); i++) {
			int x = activePositions[i].x;
			int y = activePositions[i].y;
			if ((*field)[x][y].hasCreature() && !done) {
				if ((*field)[x][y].currCreature->getId() != creatureId) {
					//deal damage
					(*field)[x][y].currCreature->reduceHP(10);
					dealtDamage = true;
					done = true;
				}
			}
		}
	}

	void AttackMove::setDone() {
		done = true;
	}

	bool AttackMove::isDone() {
		return done;
	}
}

