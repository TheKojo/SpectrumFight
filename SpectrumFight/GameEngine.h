#pragma once

#include "SFML/Graphics.hpp"

namespace Spectrum {
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();

		void start();
		sf::RenderWindow gameWindow;
		GameEngine* gEngine;

		sf::RenderWindow* getWindow();
	};
}


