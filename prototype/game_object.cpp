//
// Created by viktor on 2020-11-25.
//

#include "game_object.h"

Game_Object::Game_Object(sf::Sprite sprite)
: sprite{sprite}
{}


void Game_Object::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}