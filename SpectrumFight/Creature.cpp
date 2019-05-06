#include "Creature.h"
#include "BattleAI.h"

namespace Spectrum{
	Creature::Creature()
	{
	}


	Creature::~Creature()
	{
	}


	void Creature::setId(int newId, bool player) {
		id = newId;
		hp = 50;
		speed = 200;
		moveTimer = 0;
		isPlayer = player;
		if (!isPlayer) {
			AI.setAI(BattleAI::Random);
		}
		
	}

	int Creature::getId() {
		return id;
	}

	void Creature::move(Movement dir) {
		if (isMoving == true) {
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
			isMoving = true;
			oldCoord = tilePositions(oldPosition);
			curCoord = oldCoord;
			finalCoord = tilePositions(position);
		}
	}

	void Creature::moveUp(){
		switch (position) {
			case TopLeft:
				position = TopLeft;
				break;
			case TopCenter:
				position = TopCenter;
				break;
			case TopRight:
				position = TopRight;
				break;
			case MiddleLeft:
				position = TopLeft;
				break;
			case MiddleCenter:
				position = TopCenter;
				break;
			case MiddleRight:
				position = TopRight;
				break;
			case BottomLeft:
				position = MiddleLeft;
				break;
			case BottomCenter:
				position = MiddleCenter;
				break;
			case BottomRight:
				position = MiddleRight;
				break;
			case oTopLeft:
				position = oTopLeft;
				break;
			case oTopCenter:
				position = oTopCenter;
				break;
			case oTopRight:
				position = oTopRight;
				break;
			case oMiddleLeft:
				position = oTopLeft;
				break;
			case oMiddleCenter:
				position = oTopCenter;
				break;
			case oMiddleRight:
				position = oTopRight;
				break;
			case oBottomLeft:
				position = oMiddleLeft;
				break;
			case oBottomCenter:
				position = oMiddleCenter;
				break;
			case oBottomRight:
				position = oMiddleRight;
				break;
		}

	}

	void Creature::moveLeft() {
		switch (position) {
			case TopLeft:
				position = TopLeft;
				break;
			case TopCenter:
				position = TopLeft;
				break;
			case TopRight:
				position = TopCenter;
				break;
			case MiddleLeft:
				position = MiddleLeft;
				break;
			case MiddleCenter:
				position = MiddleLeft;
				break;
			case MiddleRight:
				position = MiddleCenter;
				break;
			case BottomLeft:
				position = BottomLeft;
				break;
			case BottomCenter:
				position = BottomLeft;
				break;
			case BottomRight:
				position = BottomCenter;
				break;
			case oTopLeft:
				position = oTopLeft;
				break;
			case oTopCenter:
				position = oTopLeft;
				break;
			case oTopRight:
				position = oTopCenter;
				break;
			case oMiddleLeft:
				position = oMiddleLeft;
				break;
			case oMiddleCenter:
				position = oMiddleLeft;
				break;
			case oMiddleRight:
				position = oMiddleCenter;
				break;
			case oBottomLeft:
				position = oBottomLeft;
				break;
			case oBottomCenter:
				position = oBottomLeft;
				break;
			case oBottomRight:
				position = oBottomCenter;
				break;
		}
	}

	void Creature::moveRight() {
		switch (position) {
			case TopLeft:
				position = TopCenter;
				break;
			case TopCenter:
				position = TopRight;
				break;
			case TopRight:
				position = TopRight;
				break;
			case MiddleLeft:
				position = MiddleCenter;
				break;
			case MiddleCenter:
				position = MiddleRight;
				break;
			case MiddleRight:
				position = MiddleRight;
				break;
			case BottomLeft:
				position = BottomCenter;
				break;
			case BottomCenter:
				position = BottomRight;
				break;
			case BottomRight:
				position = BottomRight;
				break;
			case oTopLeft:
				position = oTopCenter;
				break;
			case oTopCenter:
				position = oTopRight;
				break;
			case oTopRight:
				position = oTopRight;
				break;
			case oMiddleLeft:
				position = oMiddleCenter;
				break;
			case oMiddleCenter:
				position = oMiddleRight;
				break;
			case oMiddleRight:
				position = oMiddleRight;
				break;
			case oBottomLeft:
				position = oBottomCenter;
				break;
			case oBottomCenter:
				position = oBottomRight;
				break;
			case oBottomRight:
				position = oBottomRight;
				break;
		}
	}

	void Creature::moveDown() {
		switch (position) {
			case TopLeft:
				position = MiddleLeft;
				break;
			case TopCenter:
				position = MiddleCenter;
				break;
			case TopRight:
				position = MiddleRight;
				break;
			case MiddleLeft:
				position = BottomLeft;
				break;
			case MiddleCenter:
				position = BottomCenter;
				break;
			case MiddleRight:
				position = BottomRight;
				break;
			case BottomLeft:
				position = BottomLeft;
				break;
			case BottomCenter:
				position = BottomCenter;
				break;
			case BottomRight:
				position = BottomRight;
				break;
			case oTopLeft:
				position = oMiddleLeft;
				break;
			case oTopCenter:
				position = oMiddleCenter;
				break;
			case oTopRight:
				position = oMiddleRight;
				break;
			case oMiddleLeft:
				position = oBottomLeft;
				break;
			case oMiddleCenter:
				position = oBottomCenter;
				break;
			case oMiddleRight:
				position = oBottomRight;
				break;
			case oBottomLeft:
				position = oBottomLeft;
				break;
			case oBottomCenter:
				position = oBottomCenter;
				break;
			case oBottomRight:
				position = oBottomRight;
				break;
		}
	}


	void Creature::setPosition(FieldPosition newPosition) {
		position = newPosition;
		curCoord = tilePositions(position);
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

	sf::Vector2f Creature::tilePositions(FieldPosition pos) {
		switch (pos) {
			case TopLeft:
				return sf::Vector2f(35.f, 106.f);
			case TopCenter:
				return sf::Vector2f(101.f, 106.f);
			case TopRight:
				return sf::Vector2f(167.f, 106.f);
			case MiddleLeft:
				return sf::Vector2f(35.f, 153.f);
			case MiddleCenter:
				return sf::Vector2f(101.f, 153.f);
			case MiddleRight:
				return sf::Vector2f(167.f, 153.f);
			case BottomLeft:
				return sf::Vector2f(35.f, 200.f);
			case BottomCenter:
				return sf::Vector2f(101.f, 200.f);
			case BottomRight:
				return sf::Vector2f(167.f, 200.f);
			case oTopLeft:
				return sf::Vector2f(233.f, 106.f);
			case oTopCenter:
				return sf::Vector2f(299.f, 106.f);
			case oTopRight:
				return sf::Vector2f(364.f, 106.f);
			case oMiddleLeft:
				return sf::Vector2f(233.f, 153.f);
			case oMiddleCenter:
				return sf::Vector2f(299.f, 153.f);
			case oMiddleRight:
				return sf::Vector2f(364.f, 153.f);
			case oBottomLeft:
				return sf::Vector2f(234.f, 200.f);
			case oBottomCenter:
				return sf::Vector2f(299.f, 200.f);
			case oBottomRight:
				return sf::Vector2f(364.f, 200.f);
		}

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

}
