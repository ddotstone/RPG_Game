#ifndef GAMESTATES_H
#define GAMESTATES_H

#include "State.h"

class GameState:
    public State
{
private:
    Player* player;

    //functions
    void initPlayers();
    void initKeybinds();
    void initTextures();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();
    //functions
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
#endif

