#include "GameState.h"

//Initailizers

void GameState::initPlayers()
{
	this->player = new Player(0, 0, this->textures["PlayerIdle"]);
}

void GameState::initKeybinds()
{
	std::ifstream ifs("Config\\gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}

	}
	ifs.close();
}

void GameState::initTextures()
{
	sf::Texture temp;
	if (!this->textures["PlayerIdle"].loadFromFile("Resources/Images/Sprites/Player/test.png")) {
		throw "ERROR::MAINMENUSTATE::FAILED_TO_LOAD_PLAYER_IDLE_TEXTURE";
	}
}

//Constructo/Decstructor
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) :State(window,supportedKeys,states)
{
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();
}

GameState::~GameState()
{
	delete this->player;
}

//Update
void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player->move(-1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player->move(1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player->move(0.f, -1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player->move(0.f, 1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->endState();
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->player->update(dt);
}


//Render
void GameState::render(sf::RenderTarget* target)
{
	if(!target)
	{
		target = this->window;
	}
	this->player->render(this->window);
}
