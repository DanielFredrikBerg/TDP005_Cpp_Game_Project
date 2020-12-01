//
// Created by viktor on 2020-11-25.
//

#include "game_object.h"

Game_Object::Game_Object(sf::Sprite & sprite)
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

double Game_Object::sqr_dist_to(Game_Object const& other) const
{
    double x_diff{sprite.getPosition().x - other.sprite.getPosition().x};
    double y_diff{sprite.getPosition().y - other.sprite.getPosition().y};
    return std::pow(x_diff, 2) + std::pow(y_diff, 2);
}

double Game_Object::x_dist_to(Game_Object const& other) const
{
    return sprite.getPosition().x - other.sprite.getPosition().x;
}

double Game_Object::y_dist_to(Game_Object const& other) const
{
    return sprite.getPosition().y - other.sprite.getPosition().y;
}