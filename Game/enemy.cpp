

#include "enemy.h"


Update_Result Enemy::update(sf::Time const& time, Level & level)
{
    // enemy-type specific behaviors
    for (auto behavior : behaviors)
    {
        behavior -> update(time, level, *this);
    }

    // move, then resolve collisions
    Moving_Object::update(time, level);

    return Update_Result::none;
}

void Enemy::resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions)
{}