//
// Created by viktor on 2020-11-21.
//

#ifndef SFML_TEST_INGAME_H
#define SFML_TEST_INGAME_H

#include "game_state.h"
#include "level.h"

class Ingame : public Game_State
{
public:
private:
    //Level level;
    int level_nr;
    // a test

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFML_TEST_INGAME_H
