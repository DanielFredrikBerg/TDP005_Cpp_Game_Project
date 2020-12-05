

#include "game_state.h"


Game_State::Game_State(std::string const& file_name)
: level{Level_Loader::load_level(file_name)}, level_name{file_name}
{}

std::shared_ptr<State> Game_State::update(sf::Time time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        return std::make_shared<Menu_State>(menu_type::pause, shared_from_this());
    }

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