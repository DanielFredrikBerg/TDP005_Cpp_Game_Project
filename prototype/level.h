//
// Created by viktor on 2020-11-21.
//

#ifndef SFML_TEST_LEVEL_H
#define SFML_TEST_LEVEL_H

#include <SFML/Graphics.hpp>

class Level : public sf::Drawable
{
public:
    Level();
    void load_level();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFML_TEST_LEVEL_H
