#include "SFML/Graphics.hpp"
#pragma once

namespace Spectrum {
	class Animation
	{
	public:
		Animation();
		~Animation();
		struct Frame {
			sf::IntRect rect;
			double duration;
		};

		std::vector<Frame> frames;
		sf::Sprite* target;

		void setSprite(sf::Sprite* target);
		void addFrame(Frame&& frame);
		void update();

		int curFrame;
		double frameTimeCounter;

	};
}


