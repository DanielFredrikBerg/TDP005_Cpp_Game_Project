//
// Created by viktor on 2020-11-25.
//

#include <iostream>
#include "game_object.h"

Game_Object::Game_Object(sf::Sprite & sprite, int width, int height)
: sprite{sprite}, width{width}, height{height}
{}

bool Game_Object::collides_with(Game_Object const& other) const
{
    return sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds());
}

void Game_Object::draw(sf::RenderWindow &window)
{
    sf::IntRect tr{sprite.getTextureRect()};

    if (animation_frames > 1 && animation_timer.asMilliseconds() > ms_per_frame)
    {
        // reset animation timer
        animation_timer = sf::Time{};

        // update current animation frame
        current_frame = ++current_frame % animation_frames;
    }

    if (animation_frames > 1)
    {
        tr.left = current_frame * 16;
    }

    // flip sprite left/right
    if (flip_sprite)
    {
        tr.left += 16;
        tr.width = -16;
    }
    else
    {
        tr.width = 16;
    }

    sprite.setTextureRect(tr);
    window.draw(sprite);
}

sf::Vector2f Game_Object::get_position()
{
    return sf::Vector2f{sprite.getPosition().x, sprite.getPosition().y};
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