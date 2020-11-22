//
// Created by viktor on 2020-11-21.
//

#include "game.h"
#include "ingame.h"

using namespace sf;

Game::Game()
: window{RenderWindow{VideoMode(1024,768), "TDP005 Platformer"}},
  state_stack{std::vector<Game_State*>{}}, event{Event{}}, timer{Clock{}}
{
    state_stack.push_back(new Ingame{});
}

void Game::process_input()
{
    switch (event.type)
    {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:
            break;

        case sf::Event::Resized:
            //window.clear();
            //window.display();
            break;

        case sf::Event::MouseEntered:
            window.clear(sf::Color::White);
            break;

        case sf::Event::MouseLeft:
            window.clear(sf::Color::Black);
            break;

        default:
            break;
    }
}

void Game::run()
{
    // create ingame state

    // create main menu state

    // misc settings
    //window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    // game loop
    while (window.isOpen())
    {
        // process user input
        while (window.pollEvent(event))
        {
            process_input();
        }

        // take a short nap
        sleep(seconds(0.05));

        //Time delta = clock.restart();
        //std::cout << delta.asMilliseconds() << std::endl;
        //x += delta.asMilliseconds() * speed / 1000.0f;

        // clear screen
        //window.clear();

        // add stuff to the draw buffer

        // draw game
        window.display();
    }

}