
#ifndef JUMPING_ENEMY_H
#define JUMPING_ENEMY_H

#include "enemy.h"

class Jumping_Enemy : public Enemy
{
public:
    using Enemy::Enemy;

    Update_Result update(sf::Time const& time, Level & level) override;
};


#endif //GAME_JUMPING_ENEMY_H
