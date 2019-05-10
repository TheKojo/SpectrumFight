#pragma once
#include "Creature.h"
#include "Attack.h"
#include "AttackMove.h"

namespace Spectrum {
	class FieldTile
	{
	public:
		FieldTile();
		~FieldTile();

		Creature* currCreature;
		Attack* currAttack;


		void setCreature(Creature*);
		void removeCreature();
		bool hasCreature();

		void setAttack(Attack*);
		void removeAttack();
		void update(); 
	};

}


