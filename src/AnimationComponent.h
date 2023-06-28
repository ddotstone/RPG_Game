#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <iostream>
#include <string>
#include <map>

#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class AnimationComponent
{
private:
	class Animation {
	public:
		//Variables
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float timer;
		float animationTimer;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Texture& texture_sheet, sf::Sprite& sprite, float animationTimer, int start_frame_x, int start_frame_y, int frames_x, int frames_y,int width, int height):textureSheet(texture_sheet),sprite(sprite),width(width),height(height),animationTimer(animationTimer)
		{
			this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(frames_x*width, frames_y*height, width, height);

			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
			

		}
		void play(const float& dt) {

			//Update Timer
			this->timer = 10.f * dt;
			if (this->timer >= this->animationTimer) {

				//Reset Timer
				this->timer = 0.f;

				//Animation
				if (this->currentRect != this->endRect) {
					this->currentRect.left += this->width;
				}
				else {
					this->currentRect.left = this->startRect.left;
				}

				this->sprite.setTextureRect(this->currentRect);

			}
		}
		void reset() {
			this->currentRect = this->startRect;
			this->timer = 0.f;
		}
	};
	
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	//functions

	void addAnimation(
		const std::string key, 
		float animationTimer, 
		int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height);

	void play(const std::string key, const float& dt);
};
#endif

