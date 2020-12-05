
#ifndef ENEMY_H
#define ENEMY_H

#include <memory>

#include "moving_object.h"
#include "behavior.h"

class Enemy : public Moving_Object
{
public:
    using Moving_Object::Moving_Object;

    void update(sf::Time const& time, Level & level) override;

private:
    std::vector<std::shared_ptr<Behavior>> behaviors;
};


#endif
