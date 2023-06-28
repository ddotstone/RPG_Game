#ifndef ENTITY_H
#define ENTITY_H 

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

class Entity
{
private:

protected:
	sf::RectangleShape shape;
	float movementSpeed;
public:
	//Constructor/Destructor
	Entity();
	virtual ~Entity();

	//Functions
	virtual void move(const float& move, const float dir_x, const float dir_y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};
#endif

