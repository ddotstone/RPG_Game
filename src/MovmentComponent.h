#ifndef MOVMENTCOMPONENT_H
#define MOVMENTCOMPONENT_Ha

#include <iostream>
#include <vector>
#include<ctime>
#include<cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>


#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;

	//Initializer Functions

public:
	MovementComponent(sf::Sprite& sprite, float velocity, float acceleration, float deceleration);
	virtual ~MovementComponent();

	//Accessors
	
	const sf::Vector2f& getVelocity() const;
	//functions
	void move(const float dir_x, const float dir_y,const float& dt);
	void update(const float& dt);

};
#endif

