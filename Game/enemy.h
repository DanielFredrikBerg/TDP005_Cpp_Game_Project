
#ifndef ENEMY_H
#define ENEMY_H

#include <memory>

#include "moving_object.h"
#include "behavior.h"

enum class Enemy_Animation : int
{
    walking, flying, jumping
};

class Enemy : public Moving_Object
{
public:
    using Moving_Object::Moving_Object;

    Update_Result update(sf::Time const& time, Level & level) override;

    void resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions) override;

    void animate() override;



private:
    std::vector<std::shared_ptr<Behavior>> behaviors;

    int health;
};


#endif
