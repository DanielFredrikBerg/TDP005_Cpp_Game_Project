//
// Created by viktor on 2020-11-24.
//

#include "level.h"

// FOR TESTING
#include <iostream>


Level::Level(Object_ptrs stationary_objects, Object_ptrs moving_objects, Object_ptr player)
: stationary_objects{stationary_objects}, moving_objects{moving_objects}, player{player}
{}

void Level::update(sf::Time time)
{
    for (auto & obj : moving_objects)
    {
        obj -> update(time, *this);
    }

    player -> update(time, *this);
}

void Level::draw(sf::RenderWindow & window)
{
    // draw background TODO

    // draw stationary objects
    for (auto & obj : stationary_objects)
    {
        obj -> draw(window);
    }

    // draw moving objects TODO
    for (auto & obj : moving_objects)
    {
        obj -> draw(window);
    }

    // draw player
    player -> draw(window);

    // draw foreground TODO


}

Object_ptrs Level::get_collisions_stationary(Game_Object & obj) const
{
    Object_ptrs collisions;
    for (auto & other : stationary_objects)
    {
        if (obj.collides_with(*other))
        {
            collisions.push_back(other);
        }
    }

    return collisions;
}

Object_ptrs Level::get_collisions_moving(Moving_Object & obj) const
{
    Object_ptrs collisions;
    for (auto & other : moving_objects)
    {
        if (obj.collides_with(*other))
        {
            collisions.push_back(other);
        }
    }

    return collisions;
}


