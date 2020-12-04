//
// Created by viktor on 2020-11-24.
//

#include <iostream>
#include "state.h"


void State::run(sf::RenderWindow & window, std::shared_ptr<State> state)
{
    // measures elapsed time
    sf::Clock timer;

    // game loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    return;
                default:
                    break;
            }
        }

        // update the state
        state = state -> update(timer.restart());

        // exit the game
        if (!state)
        {
            return;
        }

        // clear the screen
        window.clear();

        // add stuff to the draw buffer
        state -> draw(window);

        // draw to the screen
        window.display();
    }
}