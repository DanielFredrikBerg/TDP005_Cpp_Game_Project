//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_MOVING_OBJECT_H
#define SFML_TEST_MOVING_OBJECT_H

#include "game_object.h"

class Level; // forward declaration

class Moving_Object : public Game_Object
{
public:
    Moving_Object(sf::Sprite & sprite, int width = 48, int height = 48);

    virtual void update(sf::Time const& time, Level & level) = 0;

protected:
    sf::Vector2f velocity;

    sf::IntRect texture_rect{sprite.getTextureRect()};

private:
    void handle_collision_with_stationary(Level & level);


};


#endif //SFML_TEST_MOVING_OBJECT_H
