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
		repeat = true;
		playOnce = false;
		done = false;
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
		frameTimeCounter += 0.01;//0.005;



		if (!(!repeat && curFrame == frames.size() - 1)) {
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

	void Animation::update(sf::Sprite* spriteTarget) {

		if (done) {
			return;
		}

		spriteTarget->setTextureRect(frames[curFrame].rect);
		frameTimeCounter += 0.01;//0.005;

		if (playOnce && curFrame == frames.size() - 1) {
			frames.clear();
			spriteTarget->setTextureRect(sf::IntRect(0,0,0,0));
			done = true;
		}
		else {
			if (!(!repeat && curFrame == frames.size() - 1)) {
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

	}

	void Animation::reset(double speed, bool repeatVal) {
		frames.clear();
		repeat = repeatVal;
		curFrame = 0;
		frameTimeCounter = 0.0;
		//Each frame is a square
		int spritesetWidth = target->getTexture()->getSize().x;
		int frameWidth = target->getTexture()->getSize().y;

		for (int i = 0; i < spritesetWidth / frameWidth; i++) {
			addFrame({ sf::IntRect(frameWidth*i,0,frameWidth,frameWidth), speed });
		}
	}

}

