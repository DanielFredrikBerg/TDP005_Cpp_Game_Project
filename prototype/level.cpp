//
// Created by viktor on 2020-11-24.
//

#include "level.h"

// FOR TESTING
#include <iostream>


Level::Level()
: sprite_sheet{sf::Texture{}}
{
    sprite_sheet.loadFromFile("../Media/environment-tiles.png");
}

void Level::update(sf::Time time)
{
    for (auto & obj : moving_objects)
    {
        obj -> update(time, *this);
        // std::cout << "hello there" << std::endl;
    }
}

void Level::draw(sf::RenderWindow & window)
{
    for (auto & obj : stationary_objects)
    {
        obj -> draw(window);
    }

    for (auto & obj : moving_objects)
    {
        obj -> draw(window);
    }

}

void Level::add_stationary(std::shared_ptr<Game_Object> obj)
{
    stationary_objects.push_back(obj);
}

void Level::add_moving(std::shared_ptr<Moving_Object> obj, bool front)
{
    if (front)
    {
        moving_objects.push_front(obj);
    }
    else
    {
        moving_objects.push_back(obj);
    }
}


Stationary_Objects Level::get_collisions_stationary(Game_Object & obj) const
{
    Stationary_Objects collisions;
    for (auto & other : stationary_objects)
    {
        if (obj.collides_with(*other))
        {
            collisions.push_back(other);
        }
    }

    return collisions;
}

Moving_Objects Level::get_collisions_moving(Game_Object & obj) const
{
    Moving_Objects collisions;
    for (auto & other : moving_objects)
    {
        if (obj.collides_with(*other))
        {
            collisions.push_back(other);
        }
    }

    return collisions;
}


