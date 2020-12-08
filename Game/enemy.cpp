

#include "enemy.h"


void Enemy::update(sf::Time const& time, Level & level)
{

    for (auto behavior : behaviors)
    {
        behavior -> update(time, level, *this);
    }

    Moving_Object::update(time, level);
}

void Enemy::resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions)
{}