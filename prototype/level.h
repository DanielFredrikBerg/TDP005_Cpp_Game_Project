//
// Created by viktor on 2020-11-24.
//

#ifndef SFML_TEST_LEVEL_H
#define SFML_TEST_LEVEL_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "game_object.h"
#include "moving_object.h"

// TEMPORARY
#include "player.h"

class Level
{
public:
    Level();

    void update(sf::Time time);

    void draw(sf::RenderWindow & window);

    auto find_collisions(Game_Object const& obj) const;

    // TEMPORARY FUNCTION FOR CREATING A TEST LEVEL
    void load_level();

private:
    sf::Texture sprite_sheet;
    std::vector<std::shared_ptr<Game_Object>> stationary_objects;
    std::vector<std::unique_ptr<Moving_Object>> moving_objects;

    /* TEMPORARY PLAYER TEXTURE
     * TODO: add all sprites into one file and load it into sprite_sheet member variable
     */
    sf::Texture player_texture{};

};


#endif //SFML_TEST_LEVEL_H
