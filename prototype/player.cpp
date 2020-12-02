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

    // handle collision with moving objects
    // TODO

    // move player and handle collision with stationary objects
    Moving_Object::update(time, level);

    // put in Game_Object.update() ?
    animation_timer += time;

    // change animation frame
    animate_player();







    sprite.setTextureRect(sf::IntRect{texture_rect});




}

void Player::handle_input(sf::Time const& time)
{
    // update jump timer
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

void Player::animate_player()
{
    // jumping frame
    if (velocity.y != 0 && time_since_jump.asMilliseconds() < 50 )
    {
        animation_frames = 1;
        texture_rect.left = 0;
        texture_rect.top = 16;
    }
    // falling frame
    else if (velocity.y != 0)
    {
        animation_frames = 1;
        texture_rect.top = 0;
        texture_rect.left = 0;
    }
    // walking animation
    else if (velocity.x != 0)
    {
        // adjust animation frame rate based on player velocity
        ms_per_frame = 300 - (abs(velocity.x) * 0.5);

        animation_frames = 4;
        texture_rect.top = 0;
        texture_rect.left = 0;
    }
    // standing frame
    else
    {
        animation_frames = 1;
        texture_rect.top = 16;
        texture_rect.left = 16;
    }

    // apply changes to sprite
    //sprite.setTextureRect(texture_rect);
}