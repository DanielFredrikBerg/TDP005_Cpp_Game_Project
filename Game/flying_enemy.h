
#ifndef FLYING_ENEMY_H
#define FLYING_ENEMY_H

#include "enemy.h"

class Flying_Enemy : public Enemy
{
public:
    using Enemy::Enemy;

    Update_Result update(sf::Time const& time, Level & level) override;

    void animate() override;
};


#endif
