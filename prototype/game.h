//
// Created by viktor on 2020-11-21.
//

#ifndef SFML_TEST_GAME_H
#define SFML_TEST_GAME_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "game_state.h"

class Game {
public:
    Game();
    void run();
private:
    sf::RenderWindow window;
    std::vector<Game_State*> state_stack;
    sf::Event event;
    sf::Clock timer;

    void process_input();
};


#endif //SFML_TEST_GAME_H
