//
// Created by viktor on 2020-11-25.
//

#include "game_object.h"

Game_Object::Game_Object(sf::Sprite sprite)
: sprite{sprite}
{}

bool Game_Object::collides_with(Game_Object const& other) const
{
    return sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds());
}

void Game_Object::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}