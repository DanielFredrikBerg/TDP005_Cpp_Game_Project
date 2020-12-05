
#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "level.h"

class Enemy;

class Behavior
{
public:
    virtual void update(sf::Time const& time, Level & level, Enemy & enemy) = 0;

private:

};


#endif
