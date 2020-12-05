
#include <SFML/Graphics.hpp>

#include "menu_state.h"
#include "menu_type.h"

int main()
{
    sf::RenderWindow window{sf::VideoMode{1152, 960}, "TDP005 Platformer"};
    //window.setVerticalSyncEnabled(true);
    sf::View view{sf::FloatRect{0,0, 1152, 960}};
    window.setView(view);

    State::run(window, std::make_shared<Menu_State>(menu_type::main));

    return 0;
}
