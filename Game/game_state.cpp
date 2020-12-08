

#include "game_state.h"


Game_State::Game_State(std::string const& level_name)
: level{Level_Loader::load_level(level_name)}, level_name{level_name}
{}

std::shared_ptr<State> Game_State::take_user_input(sf::Time time)
{
    // pause a level
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        return std::make_shared<Menu_State>(Menu_Type::pause, shared_from_this());
    }

    return shared_from_this();
}


std::shared_ptr<State> Game_State::update(sf::Time time)
{
    // update the level
    level -> update(time);

    return shared_from_this();
}

void Game_State::draw(sf::RenderWindow & window)
{
    level -> draw(window);
}

std::string Game_State::get_level_name() const
{
    return level_name;
}