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
    Ingame();
private:
    Level level;
    int level_nr;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //SFML_TEST_INGAME_H
