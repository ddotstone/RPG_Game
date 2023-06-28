#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet) : sprite(sprite), textureSheet(texture_sheet)
{
}

AnimationComponent::~AnimationComponent()
{
	for (std::pair<const std::string, Animation*>& i : this->animations) {
		delete i.second;
		i.second = 0;
	}
}

//functions

void AnimationComponent::addAnimation(
	const std::string key,
	float animationTimer, 
	int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height) {

	this->animations[key] = new Animation(
		this->textureSheet, this->sprite,
		animationTimer,
		start_frame_x, start_frame_y, frames_x, frames_y, width, height);

}

void AnimationComponent::play(const std::string key, const float& dt){
	this->animations[key]->play(dt);
}
