

#ifndef PLAYER_H
#define PLAYER_H

#include <utility>
#include <algorithm>

#include "moving_object.h"
#include "game_object.h"
#include "level.h"
#include "enemy.h"

class Player : public Moving_Object
{
public:
    Player(sf::Sprite & sprite, sf::Sprite & health_bar);

    void update(sf::Time const& time, Level & level) override;

    void draw(sf::RenderWindow & window) override;

private:
    sf::Time time_since_jump;

    sf::Time time_since_damage;

    int health{3};

    sf::Sprite health_bar;

    void handle_input(sf::Time const& time);

    void handle_collisions(sf::Time const& time, Level & level);

    void animate_player();
};


#endif
