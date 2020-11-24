//
// Created by viktor on 2020-11-21.
//

#include "ingame.h"

Ingame::Ingame()
: level{Level{}}, level_nr{1}
{}

void Ingame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    level.draw(target, states);
}