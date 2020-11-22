//
// Created by viktor on 2020-11-21.
//

#ifndef SFML_TEST_LEVEL_H
#define SFML_TEST_LEVEL_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "game_object.h"

class Level : public sf::Drawable
{
public:
    void load_level();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::string filename;
    std::vector<Game_Object*> terrain;
};


#endif //SFML_TEST_LEVEL_H
