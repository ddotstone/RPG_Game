#ifndef ENTITY_H
#define ENTITY_H

#include "AnimationComponent.h"
#include "MovmentComponent.h"

class Entity
{
private:
	void initVariables();

protected:
	sf::Sprite sprite;

	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
public:
	//Constructor/Destructor
	Entity();
	virtual ~Entity();
	//Component Functions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration,const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);
	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& move);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};
#endif

