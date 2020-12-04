//
// Created by viktor on 2020-11-24.
//

#ifndef SFML_TEST_LEVEL_H
#define SFML_TEST_LEVEL_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "moving_object.h"

using Object_ptrs = std::vector<std::shared_ptr<Game_Object>>;
using Object_ptr = std::shared_ptr<Game_Object>;

class Game_Object;

class Level
{
public:
    Level(Object_ptrs bg, Object_ptrs so, Object_ptrs mo, Object_ptrs fg, Object_ptr p);

    void update(sf::Time time);

    void draw(sf::RenderWindow & window);

    Object_ptrs get_collisions_stationary(Game_Object & obj) const;

    Object_ptrs get_collisions_moving(Moving_Object & obj) const;

    sf::Vector2f get_player();

private:
    Object_ptrs background;
    Object_ptrs stationary_objects;
    Object_ptrs moving_objects;
    Object_ptrs foreground;

    Object_ptr player;

};


#endif //SFML_TEST_LEVEL_H
