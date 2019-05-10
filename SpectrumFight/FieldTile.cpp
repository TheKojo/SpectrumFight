#include "FieldTile.h"
#include "Creature.h"
#include "Attack.h"
#include "AttackMove.h"


namespace Spectrum {
	FieldTile::FieldTile()
	{
	}


	FieldTile::~FieldTile()
	{
	}

	void FieldTile::setCreature(Creature* newCreature) {
		currCreature = newCreature;
	}

	void FieldTile::removeCreature() {
		currCreature = nullptr;
	}

	bool FieldTile::hasCreature() {
		if (currCreature) {
			return true;
		}
		else {
			return false;
		}
	}

	void FieldTile::setAttack(Attack* newAttack) {
		currAttack = newAttack;
	}

	void FieldTile::removeAttack() {
		
	}

	//checked every iteration of the main loop; 
	//check if attack and creature are on same tile and if so deal damage; 
	//call update() on attack object and remove if duration is over
	//TODO: change currAttack to separate value rather than pointer?
	void FieldTile::update() {
	/*	if (currAttack && currCreature) {
			if ((currAttack->getCreatureId() != currCreature->getId()) && !currAttack->moveController->isDone()) {
				//deal damage to creature
				currCreature->reduceHP(currAttack->getDamage());
				currAttack->dealtDamage = true;
				currAttack->setDone();
			}

		}*/
	}
}

