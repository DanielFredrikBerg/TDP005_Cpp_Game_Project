//
// Created by viktor on 2020-11-24.
//

#include "level.h"

// FOR TESTING
#include <iostream>


Level::Level(Object_ptrs bg, Object_ptrs so, Object_ptrs mo, Object_ptrs fg, Object_ptr p)
: background{bg}, stationary_objects{so}, moving_objects{mo}, foreground{fg}, player{p}
{}

void Level::update(sf::Time time)
{
    for (auto & obj : background)
    {
        obj -> update(time, *this);
    }

    for (auto & obj : moving_objects)
    {
        obj -> update(time, *this);
    }

    player -> update(time, *this);
}

void Level::draw(sf::RenderWindow & window)
{
    // draw background
    for (auto & obj : background)
    {
        obj -> draw(window);
    }

    // draw stationary objects
    for (auto & obj : stationary_objects)
    {
        obj -> draw(window);
    }

    // draw moving objects
    for (auto & obj : moving_objects)
    {
        obj -> draw(window);
    }

    // draw player
    player -> draw(window);

    // draw foreground
    for (auto & obj : foreground)
    {
        obj -> draw(window);
    }


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


