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
    if (velocity.y == 0)
    {
        time_since_jump += time;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (velocity.y == 0 && time_since_jump.asMilliseconds() > 50)
        {
            velocity.y -= 900;
            time_since_jump = sf::Time{};
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity.x = std::max(-400.0f, velocity.x - 1200 * time.asSeconds());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity.x = std::min(400.0f, velocity.x + 1200 * time.asSeconds());
    }
    else
    {
        if (velocity.x > 1200 * time.asSeconds())
        {
            velocity.x -= 1200 * time.asSeconds();
        }
        else if (velocity.x < -1200 * time.asSeconds())
        {
            velocity.x += 1200 * time.asSeconds();
        }
        else
        {
            velocity.x = 0;
        }

    }

    sprite.move(velocity.x * time.asSeconds(), velocity.y * time.asSeconds());

    Moving_Object::update(time, level);
}