//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_GAME_OBJECT_H
#define SFML_TEST_GAME_OBJECT_H

#include <SFML/Graphics.hpp>

class Game_Object
{
public:
    Game_Object(sf::Sprite sprite);

    virtual void draw(sf::RenderWindow & window);
protected:
    sf::Sprite sprite;
};


#endif //SFML_TEST_GAME_OBJECT_H
