//
// Created by viktor on 2020-11-25.
//

#include "menu_state.h"


// start menu
Menu_State::Menu_State()
: game{std::make_shared<Game_State>("level1")}, selected{0}
{
    font.loadFromFile("../Media/font.ttf");

    menu_items.push_back(Menu_Item{sf::Text{"Start Game", font, 60}, [this]() { return game;}});
    menu_items.push_back(Menu_Item{sf::Text{"Level Select", font, 60}, [this]() { return shared_from_this();}}); // TODO
    menu_items.push_back(Menu_Item{sf::Text{"Options", font, 60}, [this]() { return shared_from_this();}});   // TODO
    menu_items.push_back(Menu_Item{sf::Text{"Exit", font, 60}, []() { return nullptr;}});
}

// pause menu
Menu_State::Menu_State(std::shared_ptr<State> gs)
: game{std::dynamic_pointer_cast<Game_State>(gs)}, selected{0}
{
    font.loadFromFile("../Media/font.ttf");

    menu_items.push_back(Menu_Item{sf::Text{"Continue", font, 60}, [this]() { return game;}});

    menu_items.push_back(Menu_Item{sf::Text{"Retry", font, 60},
                                   [this]() { return std::make_shared<Game_State>(game -> get_level_name()); }} );

    menu_items.push_back(Menu_Item{sf::Text{"Main Menu", font, 60},
                                   [this]() { return std::make_shared<Menu_State>();}});

    menu_items.push_back(Menu_Item{sf::Text{"Exit", font, 60}, []() { return nullptr;}});
}


std::shared_ptr<State> Menu_State::update(sf::Time time)
{
    delay += time;
    if (delay.asMilliseconds() > 200)
    {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
        {
            return menu_items[selected].action();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            selected = std::max(selected - 1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            selected = (selected + 1) % menu_items.size();
        }
        else
        {
            return shared_from_this();
        }
        delay = sf::Time{};
    }

    return shared_from_this();
}


void Menu_State::draw(sf::RenderWindow & window)
{
    game -> draw(window);

    auto view_position = window.getView().getCenter();
    auto window_size = window.getSize();
    auto y{view_position.y - window_size.y / 4};

    for (auto i{0}; i < menu_items.size(); ++i)
    {
        auto bounds = menu_items[i].text.getLocalBounds();
        menu_items[i].text.setPosition((window_size.x - bounds.width) / 2, y);
        y += bounds.height * 2.0f;

        if (i == selected)
        {
            menu_items[i].text.setFillColor(sf::Color(255, 255, 0));
        }
        else
        {
            menu_items[i].text.setFillColor(sf::Color(255, 255, 255));
        }

        window.draw(menu_items[i].text);
    }


}