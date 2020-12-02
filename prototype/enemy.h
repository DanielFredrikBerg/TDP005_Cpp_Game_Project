//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_ENEMY_H
#define SFML_TEST_ENEMY_H

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


#endif //SFML_TEST_ENEMY_H
