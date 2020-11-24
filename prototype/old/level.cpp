//
// Created by viktor on 2020-11-21.
//

#include <iostream>

#include "level.h"
#include "terrain.h"

Level::Level()
: texture{sf::Texture{}}, terrain{std::vector<Game_Object*>{}}
{
    texture.loadFromFile("Sprites/tiles.png");
    load_level();
}

void Level::load_level()
{
    Terrain* obj{new Terrain{0, 0, texture}};

    terrain.push_back(obj);
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (Game_Object* go : terrain)
    {
        go->draw(target, states);
    }
}