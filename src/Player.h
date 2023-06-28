#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
class Player :
    public Entity
{
private:
    //Variables
    
    //Initailizer Functions
    void initVariables();
    void initComponents();
public:
    Player(float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    //functions
};
#endif

