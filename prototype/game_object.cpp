//
// Created by viktor on 2020-11-22.
//

#include <iostream>

#include "game_object.h"

Game_Object::Game_Object(int x_pos, int y_pos, sf::Texture & texture)
: x_pos{x_pos}, y_pos{y_pos}, sprite{sf::Sprite{}}
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,16,16));
    sprite.setPosition(50, 50);
}

void Game_Object::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    std::cout << sprite.getPosition().x << std::endl;
    target.draw(sprite);

    //std::cout << "game_object draw()" << std::endl;
}