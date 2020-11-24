//
// Created by viktor on 2020-11-21.
//

#ifndef SFML_TEST_GAME_STATE_H
#define SFML_TEST_GAME_STATE_H

#include <SFML/Graphics.hpp>

class Game_State : public sf::Drawable
{
public:
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};


#endif //SFML_TEST_GAME_STATE_H
