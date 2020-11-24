//
// Created by viktor on 2020-11-22.
//

#ifndef SFML_TEST_TERRAIN_H
#define SFML_TEST_TERRAIN_H

#include "game_object.h"

class Terrain : public Game_Object
{
public:
    Terrain(int x_pos, int y_pos, sf::Texture & texture);
private:

};


#endif //SFML_TEST_TERRAIN_H
