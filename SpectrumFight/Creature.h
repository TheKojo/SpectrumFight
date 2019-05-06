#include <string>
#include "SFML/Graphics.hpp"
#include "BattleAI.h"
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

		void setId(int, bool);
		int getId();
		void move(Movement);
		void moveUp();
		void moveLeft();
		void moveRight();
		void moveDown();
		void setPosition(FieldPosition);
		bool isMoving;
		sf::Vector2f getScreenPosition();
		sf::Vector2f tilePositions(FieldPosition);
		void updatePosition();
		void makeMove();

		int id;
		string name;
		int hp;
		int speed; //lower values are faster

		FieldPosition position;
		FieldPosition oldPosition;
		sf::Vector2f oldCoord;
		sf::Vector2f finalCoord;
		sf::Vector2f curCoord;
		int moveTimer;

		bool isPlayer;
		BattleAI AI;

	};
}


