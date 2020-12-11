
#include "walking_enemy.h"


Update_Result Walking_Enemy::update(sf::Time const& time, Level & level)
{
    // apply gravity
    velocity.y = std::min(velocity.y + constants::gravity_const * time.asMilliseconds(), 4.0f);

    // increment timer
    action_timer += time;

    // take action
    int num = time.asMicroseconds() % 9;
    switch (num)
    {
        case 1:
            break;
        default:
            break;
    }

    Enemy::update(time, level);
}