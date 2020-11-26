//
// Created by viktor on 2020-11-24.
//

#ifndef SFML_TEST_LEVEL_H
#define SFML_TEST_LEVEL_H

#include <SFML/Graphics.hpp>

class Level
{
public:
    Level();

    void draw(sf::RenderWindow & window);

private:
    sf::Texture sprite_sheet;

};


#endif //SFML_TEST_LEVEL_H
