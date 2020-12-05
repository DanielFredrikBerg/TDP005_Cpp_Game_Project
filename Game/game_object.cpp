
#include <iostream>
#include "game_object.h"

Game_Object::Game_Object(sf::Sprite & sprite, int animation_frames, double ms_per_frame)
: sprite{sprite}, animation_frames{animation_frames}, current_frame{0}, ms_per_frame{ms_per_frame}, flip_sprite{false}
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
        tr.left = current_frame * sprite.getLocalBounds().width + flip_sprite * tr.width;
    }

    // flip sprite left/right
    flip_sprite ? tr.width = -abs(sprite.getLocalBounds().width) : tr.width = abs(sprite.getLocalBounds().width);

    sprite.setTextureRect(tr);
    window.draw(sprite);
}

void Game_Object::update(sf::Time const& time, Level &)
{
    animation_timer += time;
}

const sf::Sprite& Game_Object::get_sprite()
{
    return sprite;
}

double Game_Object::sqr_dist_to(Game_Object const& other) const
{
    double x_diff{sprite.getPosition().x - other.sprite.getPosition().x};
    double y_diff{sprite.getPosition().y - other.sprite.getPosition().y};
    return std::pow(x_diff, 2) + std::pow(y_diff, 2);
}
