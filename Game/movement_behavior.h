

#ifndef MOVEMENT_BEHAVIOR_H
#define MOVEMENT_BEHAVIOR_H

#include "behavior.h"
#include "enemy.h"

class Flying : public Behavior
{
public:
    void update(sf::Time & time, Level & level, Enemy & enemy);
};

class Walking : public Behavior
{
public:
    void update(sf::Time & time, Level & level, Enemy & enemy);
private:
    sf::Time timer;
};

class Jumping : public Behavior
{
    void update(sf::Time & time, Level & level, Enemy & enemy);
};

#endif
