//
// Created by viktor on 2020-11-24.
//

#ifndef SFML_TEST_LEVEL_H
#define SFML_TEST_LEVEL_H

#include <deque>
#include <memory>
#include <SFML/Graphics.hpp>

#include "game_object.h"
#include "moving_object.h"

using Stationary_Objects = std::vector<std::shared_ptr<Game_Object>>;
using Moving_Objects = std::vector<std::shared_ptr<Moving_Object>>;

class Level
{
public:
    Level();

    void update(sf::Time time);

    void draw(sf::RenderWindow & window);

    //void add_background(std::shared_ptr<Game_Object> obj);

    void add_stationary(std::shared_ptr<Game_Object> obj);

    void add_moving(std::shared_ptr<Moving_Object> obj, bool front = false);

    //void add_foreground(std::shared_ptr<Game_Object> obj);

    Stationary_Objects get_collisions_stationary(Game_Object & obj) const;

    Moving_Objects get_collisions_moving(Moving_Object & obj) const;

    sf::Vector2f get_player_pos();



private:
    std::deque<std::shared_ptr<Game_Object>> stationary_objects;
    std::deque<std::shared_ptr<Moving_Object>> moving_objects;
};


#endif //SFML_TEST_LEVEL_H
