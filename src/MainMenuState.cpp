#include "MainMenuState.h"




//Constructo/Decstructor
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states):State(window,supportedKeys,states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin();it != this->buttons.end();++it) {
		delete it->second;
	}
}

//Initializers

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts\\DripOctober-vm0JA.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config\\mainmenustate_keybinds.ini");

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

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(350, 40, 150, 50,
		&this->font, "New Game", 20,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	
	this->buttons["SETTINGS_STATE"] = new Button(350, 93, 150, 50,
		&this->font, "Settings",20,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EDITOR_STATE"] = new Button(350, 146, 150, 50,
		&this->font, "Edit",20,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	
	this->buttons["EXIT_STATE"] = new Button(350, 200, 150, 50,
		&this->font, "Quit",20,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f
	(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y))
	);
    if(!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/pasta salad.png")) {
		throw("ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE");
	}
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initVariables()
{

}


//Update
void MainMenuState::updateInput(const float& dt)
{
	
}

void MainMenuState::updateButtons()
{
	//Update all the buttons in the state and handles their functions
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	//New Game
	if (this->buttons["GAME_STATE"]->isActive()) {
		this->states->push(new GameState(this->window, this->supportedKeys,this->states));
		std::cout << "game state" << "\n";
	}
	//Quit the Game
	if (this->buttons["EXIT_STATE"]->isActive()) {
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
	
}


//Render
void MainMenuState::render(sf::RenderTarget* target)
{
	if(!target)
	{
		target = this->window;
	}
	target->draw(this->background);
	this->renderButtons(target);


	//Remove Later
	/*
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y + 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(20);
	mouseText.setFillColor(sf::Color::Green);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);
	*/
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}
