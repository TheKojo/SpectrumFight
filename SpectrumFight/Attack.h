#pragma once

namespace Spectrum {

	class AttackMove;

	class Attack
	{
	public:
		Attack();
		~Attack();

		/*enum AttackType {
			Instant = 0,
			Projectile = 1,
		};*/

		//int range;
		int damage;
		int duration; //determines how long move lasts on tile
		int creatureDelay; //determines how long creature remains stationary after using move
		//int stunDelay; //deteermines how long creature remains stunned after being hit by move
		bool fromPlayer;
		int creatureID; //for determining which creature attack came from
		AttackMove* moveController;


		bool dealtDamage;
		bool done;

		void init(int damageVal, int durationVal, int creatureDelayVal, int creatureIDVal, bool isFromPlayer, AttackMove* atkMove);
		void update(); //tick down duration
		int getDamage();
		void setDone();
		bool isDone();
		int getCreatureId();
	};
}