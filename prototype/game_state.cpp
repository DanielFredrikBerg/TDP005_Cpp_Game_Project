//
// Created by viktor on 2020-11-24.
//

#include "game_state.h"
#include "level_loader.h"

Game_State::Game_State(std::string const& file_name)
: level{Level_Loader::load_level(file_name)}
{}

std::shared_ptr<State> Game_State::update(sf::Time time)
{
    level -> update(time);
    return shared_from_this();
}

void Game_State::draw(sf::RenderWindow & window)
{
    level -> draw(window);
}