//
// Created by viktor on 2020-11-24.
//

#include "level.h"

// FOR TESTING
#include <iostream>


Level::Level()
{}

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

    // draw foreground TODO


    // draw player 1 health bar  (temp solution ?)
    health_bar.setPosition(30, player_1_position.y - 750);
    health_bar.setTextureRect(sf::IntRect{(3-player_1_health) * 32,
                                           16 * 18, 20, 16});
    window.draw(health_bar);

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

void Level::add_health_bar(sf::Sprite sprite)
{
    health_bar = sprite;
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

Moving_Objects Level::get_collisions_moving(Moving_Object & obj) const
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


