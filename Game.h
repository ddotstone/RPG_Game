#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;
	
	//Initialization
	void initWindow();
	void initKeys();
	void initStates();
public:
	
	//Constructor/Desctructor
	Game();
	virtual ~Game();
	
	//functions
	//Other
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();
	
	//Core
	void run();
};
#endif
