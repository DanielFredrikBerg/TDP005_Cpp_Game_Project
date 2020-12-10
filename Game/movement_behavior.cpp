

#include "movement_behavior.h"


void Flying::update(sf::Time & time, Level & level, Enemy & enemy)
{

}

void Walking::update(sf::Time & time, Level & level, Enemy & enemy)
{
    timer += time;
    if (timer.asMilliseconds() > 500)
    {
        int rand = time.asMicroseconds() % 6;
        // walk left
        if (rand == 0)
        {
            enemy.velocity.x = -0.5;
        }
        // walk right
        else if (rand == 1)
        {
            enemy.velocity.x = 0.5;
        }
        // stand still
        else if (rand == 2)
        {
            enemy.velocity.x = 0;
        }
        timer = sf::Time{};

    }

}

void Jumping::update(sf::Time & time, Level & level, Enemy & enemy)
{

}