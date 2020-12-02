//
// Created by viktor on 2020-11-25.
//

#include "enemy.h"



void Enemy::update(const sf::Time &time, Level &level)
{
    for (auto behavior : behaviors)
    {
        behavior -> update();
    }
}