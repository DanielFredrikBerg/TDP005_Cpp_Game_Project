//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_MENU_STATE_H
#define SFML_TEST_MENU_STATE_H

#include <string>
#include <memory>
#include <vector>

#include "state.h"
#include "game_state.h"


class Menu_State : public State
{
public:
    Menu_State();

    ~Menu_State() = default;

    std::shared_ptr<State> update(sf::Time time) override;

    void draw(sf::RenderWindow & window) override;

private:

    /**
    *   Game state to display behind the menu
    */
    std::shared_ptr<Game_State> game;

    /**
    *   Menu item.
    */
    struct Menu_Item
    {
        /**
        *   Menu item text to display on screen
        */
        sf::Text text;

        /**
        *   Action to perform when selected.
        */
        std::function<std::shared_ptr<State>()> action;
    };

    /**
    *  All menu items.
    */
    std::vector<Menu_Item> menu_items;

    /**
    * Font for menu item text.
    */
    sf::Font font;

};


#endif //SFML_TEST_MENU_STATE_H
