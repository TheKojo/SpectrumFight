#include "Attack.h"
#include "AttackMove.h"

namespace Spectrum {
	Attack::Attack()
	{
	}


	Attack::~Attack()
	{
	}
	
	void Attack::init(int damageVal, int durationVal, int creatureDelayVal, int creatureIDVal, bool isFromPlayer, AttackMove* atkMove) {
		damage = damageVal;
		duration = durationVal;
		creatureDelay = creatureDelayVal;
		fromPlayer = isFromPlayer;
		creatureID = creatureIDVal;
		moveController = atkMove;
		dealtDamage = false;
		done = false;

	}

	int Attack::getDamage() {
		return damage;
	}

	void Attack::update() {

	}

	void Attack::setDone() {
		done = true;
		moveController->setDone();
	}
	
	bool Attack::isDone() {
		return done;
	}

	int Attack::getCreatureId() {
		return creatureID;
	}
}




