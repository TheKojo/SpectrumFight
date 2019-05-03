#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "GameEngine.h"

int main() {

	const int screenWidth = 740;
	const int screenHeight = 480;

	//sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFight Window");

	Spectrum::GameEngine* engine = new Spectrum::GameEngine;
	engine->start();
	
	// Load start menu graphics
/*	sf::Texture texture;
	if (!texture.loadFromFile("images/startbg.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite startbg(texture);


	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("fonts/pkmnfl.ttf")) {
		return EXIT_FAILURE;
	}
	sf::Text text("Press Enter", font, 30);
	text.setPosition((screenWidth - text.getGlobalBounds().width)/2.f, screenHeight/2.f);

	bool started = false;
	//Game loop
	while (window.isOpen()) {

		//Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}
				
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter)) {
				started = true;

			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::S)) {
				//sprite.move(0.f, 10.f);
			}
		}

		// Clear screen
		window.clear();

		// Draw the bg
		if (!started) {
			window.draw(startbg);
		}

		// Draw the string
		if (!started) {
			window.draw(text);
		}

		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;*/
}