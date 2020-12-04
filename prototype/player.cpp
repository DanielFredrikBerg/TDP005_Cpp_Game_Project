//
// Created by viktor on 2020-11-25.
//

#include "player.h"

// TEMPORARY FOR TESTING
#include <iostream>


Player::Player(sf::Sprite & sprite, sf::Sprite & health_bar)
: Moving_Object{sprite}, health{3}, health_bar{health_bar}
{}

void Player::draw(sf::RenderWindow & window)
{
    // make window follow the player
    sf::View currentView = window.getView();
    currentView.setCenter(576, sprite.getPosition().y - window.getSize().y / 4);
    window.setView(currentView);

    // draw health bar
    health_bar.setTextureRect(sf::IntRect{(3 - health) * 32,16 * 18,24, 16});
    health_bar.setPosition(sprite.getPosition().x + 6, sprite.getPosition().y - 24);
    window.draw(health_bar);

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
    handle_collisions(time, level);

    // move player and handle collision with stationary objects
    Moving_Object::update(time, level);

    // change animation frame
    animate_player();



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

void Player::handle_collisions(sf::Time const& time, Level & level)
{
    if (time_since_damage.asMilliseconds() <= 0)
    {
        auto collisions{level.get_collisions_moving(*this)};
        for (auto & i : collisions)
        {
            if (dynamic_cast<Enemy*>(i.get()))
            {
                --health;
                time_since_damage = sf::milliseconds(1618);
            }
        }
    }
    else if (time_since_damage.asMilliseconds() > 0)
    {
        time_since_damage -= time;

        if ((time_since_damage.asMilliseconds() / 100) % 2 == 0)
        {
            sprite.setColor(sf::Color::White);
        }
        else
        {
            sprite.setColor(sf::Color::Transparent);
        }

    }
}

void Player::animate_player()
{
    int flipped{0};
    if (flip_sprite)
    {
        flipped = 14;
    }


    // jumping frame
    if (velocity.y != 0 && time_since_jump.asMilliseconds() < 50 )
    {
        animation_frames = 1;
        texture_rect.left = flipped;
        texture_rect.top = 16;
    }
    // falling frame
    else if (velocity.y != 0)
    {
        animation_frames = 1;
        texture_rect.top = 0;
        texture_rect.left = flipped;;
    }
    // walking animation
    else if (velocity.x != 0)
    {
        // adjust animation frame rate based on player velocity
        ms_per_frame = 300 - (abs(velocity.x) * 0.5);

        animation_frames = 4;
        texture_rect.top = 0;
        texture_rect.left = flipped;
    }
    // standing frame
    else
    {
        animation_frames = 1;
        texture_rect.top = 16;
        texture_rect.left = 14 + flipped;
    }

    // apply changes to sprite
    sprite.setTextureRect(texture_rect);
}