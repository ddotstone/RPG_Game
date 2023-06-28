#include "Player.h"

//Initializer Functions

void Player::initVariables() {

}
void Player::initComponents() {
}

//Constructor

Player::Player(float x, float y, sf::Texture& texture_sheet) {
	this->initVariables();

	this->setPosition(x, y);

	this->initComponents();

	this->createMovementComponent(300.f,15.f,5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_LEFT", 100.f, 0, 0, 23, 0, 900, 900);
	
}

//Destructor

Player::~Player() {

}
