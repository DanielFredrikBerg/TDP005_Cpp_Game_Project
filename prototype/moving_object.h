//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_MOVING_OBJECT_H
#define SFML_TEST_MOVING_OBJECT_H

#include "game_object.h"

class Moving_Object : public Game_Object
{
public:
    using Game_Object::Game_Object;

    virtual void update(sf::Time time) = 0;

private:

};


#endif //SFML_TEST_MOVING_OBJECT_H
