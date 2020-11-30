//
// Created by viktor on 2020-11-24.
//

#include "game_state.h"

Game_State::Game_State()
: level{Level{}}
{}

std::shared_ptr<State> Game_State::update(sf::Time time)
{
    level.update(time);
    return shared_from_this();
}

void Game_State::draw(sf::RenderWindow & window)
{
    level.draw(window);
}