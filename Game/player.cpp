

#include <iostream>
#include "player.h"

Player::Player(sf::FloatRect & rect, sf::Sprite & sprite)
: Moving_Object{rect, sprite}, time_since_jump{sf::Time{}},
  time_since_damage{sf::Time{sf::milliseconds(2000)}},
  health{3}, flip_sprite{false}, health_bar{sf::Sprite{}}
{
    // set-up health bar
    health_bar.setTexture(*sprite.getTexture());
}

void Player::draw(sf::RenderWindow & window)
{

    // update window view position
    sf::View currentView = window.getView();
    currentView.setCenter(constants::window_width / 2, rect.top);
    window.setView(currentView);

    // update health bar position & draw
    health_bar.setTextureRect(sf::IntRect{(3 - health) * 32,16 * 18,24, 16});
    health_bar.setPosition(rect.left, rect.top - 24);
    health_bar.setScale(1.5, 1.5);
    window.draw(health_bar);

    // animate & draw player
    sprite.setPosition(rect.left - ((48 - rect.width) / 2), rect.top);
    Animated_Object::draw(window);
}

Update_Result Player::update(sf::Time const& time, Level & level)
{
    // activate lava
    if (rect.top < 4200)
    {
       // level.rising_lava = true;
    }


    if (health > 0)
    {
        // handle player input
        handle_input(time);
    }
        // apply gravity
        velocity.y = std::min(velocity.y + constants::gravity_const * time.asMilliseconds(), 4.0f);

        // update damage-taken timer
        time_since_damage += time;

        // move, resolve collision, update animation
        Moving_Object::update(time, level);


    // notify Level if the player died or completed the level
    if (health <= 0 && velocity.y == 0)
    {
        return Update_Result::game_over;
    }
    else if (rect.top <= 0 && velocity.y == 0)
    {
        velocity.x = 0;
        return Update_Result::level_complete;
    }
    else
    {
        return Update_Result::none;
    }

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
            velocity.y -= 2;
            time_since_jump = sf::Time{};
        }
    }

    // move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity.x = std::max(-0.7f, velocity.x - 0.01f * time.asMilliseconds());
        flip_sprite = true;
    }
    // move right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity.x = std::min(0.7f, velocity.x + 0.01f * time.asMilliseconds());
        flip_sprite = false;
    }
    // slow down if no button is pressed
    else
    {
        if (velocity.x > 0.15)
        {
            velocity.x -= 0.005 * time.asMilliseconds();
        }
        else if (velocity.x < -0.15 )
        {
            velocity.x += 0.005 * time.asMilliseconds();
        }
        else
        {
            velocity.x = 0;
        }
    }
}

void Player::resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions)
{

    for (size_t i{0}; i < collisions.size(); ++i)
    {
        auto other_ptr{collisions.at(i).get()};
        if (dynamic_cast<Enemy*>(other_ptr) || dynamic_cast<Projectile*>(other_ptr))
        {
            if (time_since_damage.asMilliseconds() >= constants::player_invul_const)
            {
                time_since_damage = sf::Time{};
                --health;

                if (health == 0)
                {
                    velocity.y = std::max(0.001f, velocity.y);
                }
            }
            collisions.erase(collisions.begin() + i);
            --i;
        }
        else if (dynamic_cast<Lava*>(other_ptr))
        {
            health = 0;
        }
    }

    Moving_Object::resolve_collisions(collisions);
}

void Player::animate()
{
    sf::IntRect texture_rect{0,0,16,16};

    // death frame
    if (health <= 0)
    {
        texture_rect.top = 16;
        texture_rect.left = 48;
    }
    // jumping frame
    else if (velocity.y != 0 && time_since_jump.asMilliseconds() < 50 )
    {
        texture_rect.top = 16;
        texture_rect.left = 0;

    }
    // falling frame
    else if (velocity.y != 0)
    {
        texture_rect.top = 0;
        texture_rect.left = 0;
    }
    // walking animation
    else if (velocity.x != 0)
    {
        // adjust animation frame rate based on player velocity
        if (animation_timer.asMilliseconds() > 300 - fabs(velocity.x) * 300)
        {
            ++current_frame %= 4;
            animation_timer = sf::Time{};
        }

        texture_rect.top = 0;
        texture_rect.left = current_frame * 16;
    }
    // standing frame
    else
    {
        current_frame = 0;
        texture_rect.top = 16;
        texture_rect.left = 16;
    }

    // horizontal flip
    if (flip_sprite)
    {
        texture_rect.left += 16;
        texture_rect.width = -16;
    }

    // apply changes to texture
    sprite.setTextureRect(texture_rect);

    // player taking damage effect
    if (health > 0 && time_since_damage.asMilliseconds() < constants::player_invul_const)
    {
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