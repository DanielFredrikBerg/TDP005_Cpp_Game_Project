//
// Created by viktor on 2020-11-24.
//

#include "level.h"

Level::Level()
: sprite_sheet{sf::Texture{}}
{
    sprite_sheet.loadFromFile("../Media/game_example.png");
}

void Level::draw(sf::RenderWindow & window)
{
    sf::Sprite s{};
    s.setTexture(sprite_sheet);
    s.setScale(2.7,2.7);
    window.draw(s);
}
