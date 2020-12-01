//
// Created by viktor on 2020-11-24.
//

#include "menu_state.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window{sf::VideoMode{1152, 960}, "TDP005 Platformer"};
    sf::View view{sf::FloatRect{0,0, 1152, 960}};
    window.setView(view);

    State::run(window, std::make_shared<Menu_State>());

    return 0;
}
