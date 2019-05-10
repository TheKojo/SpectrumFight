#include "Animation.h"


namespace Spectrum {
	Animation::Animation()
	{
	}

	Animation::~Animation()
	{
	}

	void Animation::setSprite(sf::Sprite* newTarget) {
		target = newTarget;
		curFrame = 0;
		frameTimeCounter = 0.0;
		//Each frame is a square
		int spritesetWidth = target->getGlobalBounds().width;
		int frameWidth = target->getGlobalBounds().height;

		for (int i = 0; i < spritesetWidth/frameWidth; i++) {
			addFrame({ sf::IntRect(frameWidth*i,0,frameWidth,frameWidth), 0.5 });
		}
		
	}

	void Animation::addFrame(Frame&& frame) {
		frames.push_back(std::move(frame));
	}

	void Animation::update() {
		target->setTextureRect(frames[curFrame].rect);
		frameTimeCounter += 0.005;
		if (frameTimeCounter > frames[curFrame].duration) {
			//Move to next frame and reset counter
			curFrame += 1;
			frameTimeCounter = 0.0;
			if (frames.size() <= curFrame) {
				curFrame = 0;
			}
		}

	}

}

