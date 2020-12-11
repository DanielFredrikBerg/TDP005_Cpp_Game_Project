
#ifndef JUMPING_ENEMY_H
#define JUMPING_ENEMY_H

#include "enemy.h"

class Jumping_Enemy : public Enemy
{
public:
    using Enemy::Enemy;

    Update_Result update(sf::Time const& time, Level & level) override;

    void animate() override;
private:
    /**
     * Time since last time the enemy fired a projectile.
     */
    sf::Time time_since_fire;

    void fire(Level &level, bool direction);
};


#endif
