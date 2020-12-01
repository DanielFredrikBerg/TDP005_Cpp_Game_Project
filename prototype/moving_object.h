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
    using Game_Object::Game_Object;

    virtual void update(sf::Time const& time, Level & level) = 0;

protected:
    sf::Vector2f velocity;

private:
    void handle_collision_with_stationary(Level & level);
};


#endif //SFML_TEST_MOVING_OBJECT_H
