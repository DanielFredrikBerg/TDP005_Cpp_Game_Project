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
    // handle player input
   handle_input(time);

    // apply gravity
    velocity.y += 1600 * time.asSeconds();

    // temp ?

    animation_timer += time;

    //std::cout animation

    // temp player animation stuff ??
    if (velocity.y != 0 && time_since_jump.asMilliseconds() < 50 )
    {
        animation_frames = 1;
        texture_rect.left = 0;
        texture_rect.top = 16;
    }
    else if (velocity.x != 0)
    {
        animation_frames = 3;
        texture_rect.top = 0;
        texture_rect.left = 0;
    }
    else
    {
        animation_frames = 1;
        texture_rect.top = 16;
        texture_rect.left = 16;
    }

    //
    Moving_Object::update(time, level);


}

void Player::handle_input(sf::Time const& time)
{
    // timer
    if (velocity.y == 0)
    {
        time_since_jump += time;
    }

    // jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (velocity.y == 0 && time_since_jump.asMilliseconds() > 50)
        {
            velocity.y -= 900;
            time_since_jump = sf::Time{};
        }
    }

    // move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity.x = std::max(-400.0f, velocity.x - 1200 * time.asSeconds());
        flip_sprite = true;
    }
        // move right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity.x = std::min(400.0f, velocity.x + 1200 * time.asSeconds());
        flip_sprite = false;
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
}