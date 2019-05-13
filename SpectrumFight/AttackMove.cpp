#include "AttackMove.h"
#include "Creature.h"
#include "FieldTile.h"
#include <array>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Animation.h"
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

	void AttackMove::init(Creature* creature, std::array<std::array<FieldTile, 3>, 6>* fieldArr, GameEngine* enginePointer) {
		//physAttack.init(10, 100, 100, creature->getId(), true, this);
		field = fieldArr;
		dealtDamage = false;
		done = false;
		test = false;
		attacker = creature;
		damage = 10;
		duration = 100;
		attackerDelay = 200;
		stunDelay = 100;
		engine = enginePointer;

		startDrawMove();
		//put hitboxes on field
		activePositions.push_back(sf::Vector2i(creature->position.x + 1, creature->position.y));
		activePositions.push_back(sf::Vector2i(creature->position.x + 2, creature->position.y));
	}

	void AttackMove::update() {
		//drawMove();
		//check if creature collision within range
		for (int i = 0; i < activePositions.size(); i++) {
			int x = activePositions[i].x;
			int y = activePositions[i].y;
			if ((*field)[x][y].hasCreature() && !dealtDamage) {
				if ((*field)[x][y].currCreature->getId() != attacker->getId()) {
					//deal damage
					(*field)[x][y].currCreature->damageCreature(damage, stunDelay);
					dealtDamage = true;
					if (attackAnim.done) {
						done = true;
					}
					
				}
			}
		}

		//tick down delay on attacker
		//check if delay on attacker is finished, if so turn off


		//tick down duration
		duration -= 1;
		if (duration <= 0 && attackAnim.done) {
			done = true;
		}
	}

	void AttackMove::setDone() {
		done = true;
	}

	bool AttackMove::isDone() {
		return done;
	}

	void AttackMove::drawMove() {
		attackSprite.setTexture(attackTexture);
		attackAnim.update(&attackSprite);
		engine->gameWindow.draw(attackSprite);
	}


	void AttackMove::startDrawMove() {
		string filepath = "images/attacks/physattack.png";
		if (!attackTexture.loadFromFile(filepath)) {
			//return EXIT_FAILURE;
		}
		attackSprite.setTexture(attackTexture);
		attackSprite.setPosition(attacker->getScreenPosition().x+20, attacker->getScreenPosition().y - 80);
		attackAnim.setSprite(&attackSprite);
		attackAnim.playOnce = true;
	}
}

