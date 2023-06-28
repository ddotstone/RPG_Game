#include "MovmentComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float velocity,float acceleration, float deceleration) :
	sprite(sprite), 
	maxVelocity(velocity),
	acceleration(acceleration),
	deceleration(deceleration)
{};

MovementComponent::~MovementComponent()
{
}

//Functions

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

void MovementComponent::move(const float dir_x, const float dir_y,const float& dt)
{
	//Accelerate Object
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;


}

void MovementComponent::update(const float& dt)
{
	//Constant Deceleration and Control Maximum Velocity

    if (this->velocity.x > 0.f) {//Right Check

		//Max Velocity Check

		if (this->velocity.x > this->maxVelocity) {
			this->velocity.x = this->maxVelocity;
		}

		//Deceleration

		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f) {
			this->velocity.x = 0.f;
		}
	}
	else if (this->velocity.x < 0.f) {//Left Check

		//Max Velocity Check

		if (this->velocity.x < -this->maxVelocity) {
			this->velocity.x = -this->maxVelocity;
		}

		//Deceleration
	
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f) {
			this->velocity.x = 0.f;
		}
	}
	
	if (this->velocity.y > 0.f) {//Down Check

		//Max Velocity Check

		if (this->velocity.y > this->maxVelocity) {
			this->velocity.y = this->maxVelocity;
		}

		//Deceleration

		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f) {
			this->velocity.y = 0.f;
		}
	}
	else if (this->velocity.y < 0.f) {//Up Check
		
		//Max Velocity Check

		if (this->velocity.y < -this->maxVelocity) {
			this->velocity.y = -this->maxVelocity;
		}

		//Deceleration

		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f) {
			this->velocity.y = 0.f;
		}
	}

	//Final Move
	this->sprite.move(this->velocity * dt); //Uses Velocity

}
