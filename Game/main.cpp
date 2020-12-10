
#include <SFML/Graphics.hpp>

#include "menu_state.h"
#include "common.h"

int main()
{
    sf::RenderWindow window{sf::VideoMode{constants::window_width, constants::window_height},
                            "TDP005 Platformer",sf::Style::Close | sf::Style::Titlebar};

    window.setView(sf::View{sf::FloatRect{0,0,
                                          constants::window_width, constants::window_height}});
    //window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(500);

    State::run(window, std::make_shared<Menu_State>(Menu_Type::main));

    return 0;
}
