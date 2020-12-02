//
// Created by viktor on 2020-12-01.
//

#ifndef SFML_TEST_BEHAVIOR_H
#define SFML_TEST_BEHAVIOR_H

#include "level.h"

class Enemy;

class Behavior
{
public:
    virtual void update(sf::Time const& time, Level & level, Enemy & enemy) = 0;

private:

};


#endif //SFML_TEST_BEHAVIOR_H
