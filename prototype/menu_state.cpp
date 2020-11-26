//
// Created by viktor on 2020-11-25.
//

#include "menu_state.h"

Menu_State::Menu_State()
: game{std::make_shared<Game_State>()}
{
    font.loadFromFile("../Media/font.ttf");

    menu_items.push_back(Menu_Item{sf::Text{"Start Game", font, 60}, [this]() { return game;}});
    menu_items.push_back(Menu_Item{sf::Text{"Level Select", font, 60}, [this]() { return shared_from_this();}}); // TODO
    menu_items.push_back(Menu_Item{sf::Text{"Options", font, 60}, [this]() { return shared_from_this();}});   // TODO
    menu_items.push_back(Menu_Item{sf::Text{"Exit", font, 60}, [this]() { return nullptr;}});
}

std::shared_ptr<State> Menu_State::update(sf::Time time)
{
    return shared_from_this();
}


void Menu_State::draw(sf::RenderWindow & window)
{
    game -> draw(window);


    auto windowSize = window.getSize();
    auto y{windowSize.y / 4};

    for (auto & item : menu_items) {
        auto bounds = item.text.getLocalBounds();
        item.text.setPosition((windowSize.x - bounds.width) / 2, y);
        y += bounds.height * 2.0f;

        item.text.setFillColor(sf::Color(255, 255, 255));
        window.draw(item.text);
    }


}