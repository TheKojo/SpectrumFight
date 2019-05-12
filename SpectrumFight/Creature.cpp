#include "Creature.h"
#include "BattleAI.h"
#include "FieldTile.h"
#include <array>
using namespace std;

namespace Spectrum{
	Creature::Creature()
	{
	}


	Creature::~Creature()
	{
	}

	void Creature::init(int newId, int speciesVal, bool player, std::array<std::array<FieldTile, 3>, 6>* fieldArr, GameEngine* enginePointer) {
		engine = enginePointer;
		id = newId;
		species = speciesVal;
		isPlayer = player;
		field = fieldArr;
		totalHP = 50;
		curHP = totalHP;
		speed = 100;
		moveTimer = 0;
		isMoving = false;
		isAttacking = false;
		isStunned = false;
		isFainted = false;
		//physAttack.init(10,100,100,id,true);

		if (isPlayer) {
			position = sf::Vector2i(1, 1);
		}
		else{
			position = sf::Vector2i(4, 1);
			AI.setAI(BattleAI::Random);
		}
		curCoord = tilePositions(position);
	}

	void Creature::setId(int newId, bool player) {
		id = newId;
		totalHP = 50;
		curHP = totalHP;
		speed = 100;
		moveTimer = 0;
		isPlayer = player;
		if (!isPlayer) {
			AI.setAI(BattleAI::Random);
		}
		
	}

	int Creature::getId() {
		return id;
	}

	int Creature::getSpecies() {
		return species;
	}

	void Creature::move(Movement dir) {
		if (isMoving || isAttacking || isStunned || isFainted) {
			return;
		}
		oldPosition = position;
		switch (dir) {
			case Up:
				moveUp();
				break;
			case Left:
				moveLeft();
				break;
			case Right:
				moveRight();
				break;
			case Down:
				moveDown();
				break;
		}
		if (oldPosition != position) {
			(*field)[position.x][position.y].setCreature(this);
			(*field)[oldPosition.x][oldPosition.y].removeCreature();

			isMoving = true;
			oldCoord = tilePositions(oldPosition);
			curCoord = oldCoord;
			finalCoord = tilePositions(position);
		}
	}

	void Creature::moveUp(){
		if (position.y > 0) {
			position.y -= 1;
		}
	}

	void Creature::moveLeft() {
		if ((position.x > 0 && isPlayer) || (position.x > 3 && !isPlayer)) {
			position.x -= 1;
		}
	}

	void Creature::moveRight() {
		if ((position.x < 2 && isPlayer) || (position.x < 5 && !isPlayer)) {
			position.x += 1;
		}
	}

	void Creature::moveDown() {
		if (position.y < 2) {
			position.y += 1;
		}
	}


	sf::Vector2f Creature::getScreenPosition() {
		return curCoord;
	}

	void Creature::updatePosition() {
		if (isMoving == true) {
			curCoord.x += (finalCoord.x - oldCoord.x) / speed;
			curCoord.y += (finalCoord.y - oldCoord.y) / speed;
			moveTimer += 1;
			if (moveTimer >= speed) {
				isMoving = false;
				curCoord = finalCoord;
				moveTimer = 0;
			}
		}
	}

	sf::Vector2f Creature::tilePositions(sf::Vector2i pos) {
		sf::Vector2f screenVal;

		//x
		if (pos.x == 0) {
			screenVal.x = 35.f;
		}
		else if (pos.x == 1) {
			screenVal.x = 101.f;
		}
		else if (pos.x == 2) {
			screenVal.x = 167.f;
		}
		else if (pos.x == 3) {
			screenVal.x = 233.f;
		}
		else if (pos.x == 4) {
			screenVal.x = 299.f;
		}
		else {
			screenVal.x = 364.f;
		}

		//y
		if (pos.y == 0) {
			screenVal.y = 106.f;
		}
		else if (pos.y == 1) {
			screenVal.y = 153.f;
		}
		else {
			screenVal.y = 200.f;
		}

		return screenVal;
	}

	void Creature::makeMove() {
		int newMove = AI.makeMove();
		switch (newMove) {
			case 0:
				break;
			case 1:
				move(Up);
				break;
			case 2:
				move(Left);
				break;
			case 3:
				move(Right);
				break;
			case 4:
				move(Down);
				break;
		}
	}

	float Creature::getHPPercentage() {
		return curHP / totalHP;
	}

	void Creature::reduceHP(int val) {
		curHP -= val;
		if (curHP < 0) {
			curHP = 0;
		}
	}

	void Creature::damageCreature(int damageVal, int stunVal) {
		reduceHP(damageVal);
		isStunned = true;
		stunTimer = stunVal;
	}

	void Creature::physicalAttack() {
		if (!isMoving && !isAttacking && !isStunned) {
			AttackMove atk;
			atk.init(this, field, engine);
			activeAttacks.push_back(atk);
			isAttacking = true;
			attackDelayTimer = atk.attackerDelay;
		}
	}

	void Creature::updateAttacks() {

		if (isAttacking) {
			attackDelayTimer -= 1;
			if (attackDelayTimer <= 0) {
				attackDelayTimer = 0;
				isAttacking = false;
			}
		}

		if (isStunned) {
			stunTimer -= 1;
			if (stunTimer <= 0) {
				stunTimer = 0;
				isStunned = false;
				if (curHP == 0) {
					isFainted = true;
				}
			}
		}

		for (int i = 0; i < activeAttacks.size(); i++) {
			activeAttacks[i].update();
			if (activeAttacks[i].isDone()) {
				activeAttacks.erase(activeAttacks.begin()+i);
			}
		}
	}

	void Creature::update() {
		updatePosition();
		updateAttacks();
	}

	void Creature::drawAttacks() {
		for (int i = 0; i < activeAttacks.size(); i++) {
			activeAttacks[i].drawMove();
		}
	}

}
