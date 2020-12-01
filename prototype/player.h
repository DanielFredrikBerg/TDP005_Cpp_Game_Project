//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_PLAYER_H
#define SFML_TEST_PLAYER_H

#include <utility>
#include <algorithm>

#include "moving_object.h"

class Player : public Moving_Object
{
public:
    using Moving_Object::Moving_Object;

    void update(sf::Time time) override;
    void draw(sf::RenderWindow & window) override;

private:

};


#endif //SFML_TEST_PLAYER_H
