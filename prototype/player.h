//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_PLAYER_H
#define SFML_TEST_PLAYER_H

#include <utility>
#include <algorithm>

#include "moving_object.h"
#include "game_object.h"
#include "level.h"

class Player : public Moving_Object
{
public:
    using Moving_Object::Moving_Object;

    void update(sf::Time const& time, Level & level);
    void draw(sf::RenderWindow & window) override;

private:

};


#endif //SFML_TEST_PLAYER_H
