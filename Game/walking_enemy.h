

#ifndef WALKING_ENEMY_H
#define WALKING_ENEMY_H

#include "enemy.h"

class Walking_Enemy : public Enemy
{
public:
    using Enemy::Enemy;

    Update_Result update(sf::Time const& time, Level & level) override;

};


#endif
