

#include "enemy.h"


Update_Result Enemy::update(sf::Time const& time, Level & level)
{

    for (auto behavior : behaviors)
    {
        behavior -> update(time, level, *this);
    }

    Moving_Object::update(time, level);

    return Update_Result::none;
}

void Enemy::resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions)
{}