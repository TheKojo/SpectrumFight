#include "Creature.h"

namespace Spectrum{
	Creature::Creature()
	{
	}


	Creature::~Creature()
	{
	}


	void Creature::setId(int newId) {
		id = newId;
	}

	int Creature::getId() {
		return id;
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
		}
	}


	void Creature::setPosition(FieldPosition newPosition) {
		position = newPosition;
	}

	sf::Vector2f Creature::getScreenPosition() {
		switch (position) {
			case TopLeft:
				return sf::Vector2f (35.f, 106.f);
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
				return sf::Vector2f(234.f, 106.f);
			case oTopCenter:
				return sf::Vector2f(360.f, 106.f);
			case oTopRight:
				return sf::Vector2f(365.f, 106.f);
			case oMiddleLeft:
				return sf::Vector2f(234.f, 153.f);
			case oMiddleCenter:
				return sf::Vector2f(300.f, 153.f);
			case oMiddleRight:
				return sf::Vector2f(365.f, 153.f);
			case oBottomLeft:
				return sf::Vector2f(234.f, 200.f);
			case oBottomCenter:
				return sf::Vector2f(360.f, 200.f);
			case oBottomRight:
				return sf::Vector2f(365.f, 200.f);
		}
	}


}
