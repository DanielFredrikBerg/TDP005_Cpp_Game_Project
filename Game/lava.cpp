//
// Created by viktor on 2020-12-09.
//

#include "lava.h"

Lava::Lava(sf::FloatRect & rect, sf::Sprite & sprite, bool animated)
: Animated_Object{rect, sprite}, animated{animated}, active{false}
{}

Update_Result Lava::update(sf::Time const& time, Level & level)
{
    if (level.rising_lava)
    {
        rect.top -= 0.24 * time.asMilliseconds();
    }
    Animated_Object::update(time, level);

    return Update_Result::none;
}

/**
 * Determines which frame of an animation will be drawn.
 */
void Lava::animate()
{
    sprite.setPosition(rect.left, rect.top - 24);
    if (animated)
    {
        if (animation_timer.asMilliseconds() >=  250)
        {
            ++current_frame %= 6;
            animation_timer = sf::Time{};
        }

        sf::IntRect texture_rect{sprite.getTextureRect()};
        texture_rect.left = current_frame * 32;
        sprite.setTextureRect(texture_rect);
    }
}