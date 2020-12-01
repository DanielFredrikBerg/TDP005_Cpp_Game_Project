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
    load_level();
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


// std::vector<std::shared_ptr<Game_Object>>
// std::pair<std::vector<std::shared_ptr<Game_Object>>, std::vector<std::shared_ptr<Moving_Object>>>
std::vector<std::shared_ptr<Game_Object>> Level::find_collisions_with_stationary(Game_Object & obj) const
{
    std::vector<std::shared_ptr<Game_Object>> collisions;
    for (auto & other : stationary_objects)
    {
        if (obj.collides_with(*other))
        {
            collisions.push_back(other);
        }
    }

    return collisions;
}

/* TEMPORARY FUNCTION FOR CREATING A TEST LEVEL
 * TODO: create a singleton class that loads and saves levels
 */
void Level::load_level()
{
    // create player object
    player_texture.loadFromFile("../Media/player.png");

    sf::Sprite player_sprite;
    player_sprite.setPosition(640, 750);
    player_sprite.setScale(3,3);
    player_sprite.setTextureRect(sf::IntRect{0,0,16,16});
    player_sprite.setTexture(player_texture);

    moving_objects.push_back(std::make_unique<Player>(player_sprite, 45, 45));

    // create platforms
    sf::Sprite obj;
    obj.setTexture(sprite_sheet);
    obj.setTextureRect(sf::IntRect{5 * 16,13 * 16,16,16});
    obj.setScale(3,3);

    // bottom platform
    for (int i{0}; i < 1280; i += 48)
    {
        obj.setPosition(i, 912);
        stationary_objects.push_back(std::make_shared<Game_Object>(obj));
    }

    // lower platform
    for (int i{132}; i < 384; i += 48)
    {
        obj.setPosition(i, 720);
        stationary_objects.push_back(std::make_shared<Game_Object>(obj));
    }

    // middle platform
    for (int i{480}; i < 672; i += 48)
    {
        obj.setPosition(i, 528);
        stationary_objects.push_back(std::make_shared<Game_Object>(obj));
    }

    // 2nd middle platform
    for (int i{864}; i < 1104; i += 48)
    {
        obj.setPosition(i, 336);
        stationary_objects.push_back(std::make_shared<Game_Object>(obj));
    }

    // top platform
    for (int i{144}; i < 576; i += 48)
    {
        obj.setPosition(i, 240);
        stationary_objects.push_back(std::make_shared<Game_Object>(obj));
    }

}

