

#ifndef MOVEMENT_BEHAVIOR_H
#define MOVEMENT_BEHAVIOR_H

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

#endif
