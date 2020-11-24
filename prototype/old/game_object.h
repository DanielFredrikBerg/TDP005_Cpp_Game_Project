//
// Created by viktor on 2020-11-22.
//

#ifndef SFML_TEST_GAME_OBJECT_H
#define SFML_TEST_GAME_OBJECT_H

#include <SFML/Graphics.hpp>

class Game_Object : public sf::Drawable
{
public:
    Game_Object(int x_pos, int y_pos, sf::Texture & texture);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;



protected:
    int x_pos;
    int y_pos;
    sf::Sprite sprite;

};


#endif //SFML_TEST_GAME_OBJECT_H
