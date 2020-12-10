

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "moving_object.h"

class Projectile : public Moving_Object
{
public:
    using Moving_Object::Moving_Object;

    Update_Result update(sf::Time const& time, Level & level) override;

    void resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions) override;

    void animate() override;
private:
    bool remove{false};

    sf::Time remove_timer;
};


#endif
