

#include "enemy.h"


Update_Result Enemy::update(sf::Time const& time, Level & level)
{
    // enemy-type specific behaviors
    for (auto behavior : behaviors)
    {
        behavior -> update(time, level, *this);
    }

    // apply gravity
    velocity.y = std::min(velocity.y + constants::gravity_const * time.asMilliseconds(), 4.0f);

    // move, then resolve collisions
    Moving_Object::update(time, level);

    if (health <= 0)
    {
        return Update_Result::remove_object;
    }
    return Update_Result::none;
}

void Enemy::animate()
{
    Animated_Object::animate();
}

void Enemy::resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions)
{


    for (size_t i{0}; i < collisions.size(); ++i)
    {
        auto other_ptr{collisions.at(i).get()};
        if (dynamic_cast<Projectile*>(other_ptr))
        {

            collisions.erase(collisions.begin() + i);
            --i;
        }
        else if (dynamic_cast<Lava*>(other_ptr))
        {
            health = 0;
        }
    }

    Moving_Object::resolve_collisions(collisions);
}