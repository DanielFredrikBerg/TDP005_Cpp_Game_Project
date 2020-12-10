

#include <iostream>
#include "projectile.h"


Update_Result Projectile::update(sf::Time const& time, Level & level)
{
    Moving_Object::update(time, level);
    if(remove)
    {
        remove_timer += time;
        if (remove_timer.asMilliseconds() > 50)
        {
            std::cout << "remove" << std::endl;
            return Update_Result::remove_object;
        }
    }
    return Update_Result::none;
}

void Projectile::resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions)
{
    if (!collisions.empty())
    {
        velocity.x = 0;
        remove = true;
    }
}

void Projectile::animate()
{
    sprite.setPosition(rect.left - 12, rect.top - 12);
    sf::IntRect texture_rect{sf::IntRect{0,0,16, 16}};
    if (remove)
    {
        texture_rect.left = 48;
    }

    sprite.setTextureRect(texture_rect);
}