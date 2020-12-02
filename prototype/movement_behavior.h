//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_MOVEMENT_BEHAVIOR_H
#define SFML_TEST_MOVEMENT_BEHAVIOR_H

#include "behavior.h"

class Flying : public Behavior
{
public:
    void update(sf::Time & time, Level & level, Enemy & enemy);
};

class Walking : public Behavior
{
    void update(sf::Time & time, Level & level, Enemy & enemy);
};

class Jumping : public Behavior
{
    void update(sf::Time & time, Level & level, Enemy & enemy);
};

#endif //SFML_TEST_MOVEMENT_BEHAVIOR_H
