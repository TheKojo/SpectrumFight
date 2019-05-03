#include <string>
#include "SFML/Graphics.hpp"
using std::string;
#pragma once

namespace Spectrum {
	class Creature
	{
	public:
		Creature();
		~Creature();
		enum FieldPosition {
			TopLeft = 0,
			TopCenter,
			TopRight,
			MiddleLeft,
			MiddleCenter,
			MiddleRight,
			BottomLeft,
			BottomCenter,
			BottomRight,
			oTopLeft,
			oTopCenter,
			oTopRight,
			oMiddleLeft,
			oMiddleCenter,
			oMiddleRight,
			oBottomLeft,
			oBottomCenter,
			oBottomRight
		};

		enum Movement {
			Up = 0,
			Left,
			Right,
			Down,
		};

		void setId(int);
		int getId();
		void moveUp();
		void moveLeft();
		void moveRight();
		void moveDown();
		void setPosition(FieldPosition);
		sf::Vector2f getScreenPosition();

		int id;
		string name;
		int hp;

		FieldPosition position;
		//sf::Vector2f screenPosition;


	};
}


