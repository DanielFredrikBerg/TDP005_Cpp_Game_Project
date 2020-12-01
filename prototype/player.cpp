//
// Created by viktor on 2020-11-25.
//

#include "player.h"

// TEMPORARY FOR TESTING
#include <iostream>

void Player::draw(sf::RenderWindow & window)
{
    // make window follow the player
    sf::View currentView = window.getView();
    currentView.setCenter(576, sprite.getPosition().y - window.getSize().y / 4);
    window.setView(currentView);

    Game_Object::draw(window);
    //std::cout << "Player draw function" << std::endl;
}

void Player::update(sf::Time const& time, Level & level)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        sprite.move(0, -8);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        sprite.move(0, 8);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        sprite.move(-8, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        sprite.move(8, 0);

    auto collisions{level.find_collisions(*this)};

    // find distance to objects in collision
    std::vector<std::pair<Game_Object, double>> distances;
    for (auto & i : collisions)
    {
        distances.push_back(std::make_pair(*i, sqr_dist_to(*i)));
    }

    // reverse-sort collisions by distance
    std::sort(distances.begin(), distances.end(),
              [] (std::pair<Game_Object, double> const& a, std::pair<Game_Object, double> const& b)
              {
                return a.second > b.second;
              });

    // handle collisions in order of distance, closest first
    for (auto & i : distances)
    {
        // check if there still is a collision
        if (!collides_with(i.first))
        {
            continue;
        }

        double x_diff = x_dist_to(i.first);
        double y_diff = y_dist_to(i.first);

        // move object the shortest way out of the collision
        if (abs(x_diff) > abs(y_diff))
        {
            if (x_diff > 0)
            {

                sprite.setPosition(sprite.getPosition().x + (48 - x_diff), sprite.getPosition().y);
            }
            else
            {
                sprite.setPosition(sprite.getPosition().x - (48 + x_diff), sprite.getPosition().y);
            }
        }
        else
        {
            if (y_diff > 0)
            {
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + (48 - y_diff));
            }
            else
            {
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (48 + y_diff));
            }
        }

    }
}