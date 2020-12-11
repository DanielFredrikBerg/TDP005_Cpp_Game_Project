
#ifndef ENEMY_H
#define ENEMY_H

#include <memory>
#include <random>

#include "moving_object.h"
#include "projectile.h"
#include "lava.h"
#include "player.h"

class Enemy : public Moving_Object
{
public:
    Enemy(sf::FloatRect & rect, sf::Sprite & sprite, int health);

    Update_Result update(sf::Time const& time, Level & level) override;

    void resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions) override;

    void animate() override;


protected:
    sf::Time time_since_damage;

    sf::Time action_timer;

    int health{3};

    int random_int(int min, int max);


private:
    std::random_device rand;
};


#endif
