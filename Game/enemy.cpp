

#include "enemy.h"

Enemy::Enemy(sf::FloatRect & rect, sf::Sprite & sprite, int health)
: Moving_Object{rect, sprite}, health{health},
  time_since_damage{sf::Time{sf::milliseconds(500)}},
  action_timer{sf::Time{}}
{}

Update_Result Enemy::update(sf::Time const& time, Level & level)
{
    // increment timer
    time_since_damage += time;

    // move, then resolve collisions
    Moving_Object::update(time, level);

    if (health <= 0)
    {
        return Update_Result::remove_object;
    }
    return Update_Result::none;
}

void Enemy::animate()
{
    // walking animation
    if (velocity.x != 0)
    {
        Animated_Object::animate();
    }

    sf::IntRect texture_rect{sprite.getTextureRect()};

    // standing frame
    if (velocity.x == 0)
    {
        texture_rect.left = 0;
    }

    // flip sprite
    if (flip_sprite)
    {
        texture_rect.left += 16;
        texture_rect.width = - 16;
    }
    else
    {
        texture_rect.width = 16;
    }


    // taking damage effect
    if (health > 0 && time_since_damage.asMilliseconds() < 350)
    {
        if ((time_since_damage.asMilliseconds() / 100) % 2 == 0)
        {
            sprite.setColor(sf::Color{255,50,50});
        }
        else
        {
            sprite.setColor(sf::Color::White);
        }
    }

    sprite.setTextureRect(texture_rect);
}

void Enemy::resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions)
{


    for (size_t i{0}; i < collisions.size(); ++i)
    {
        auto other_ptr{collisions.at(i).get()};
        if (dynamic_cast<Projectile*>(other_ptr))
        {
            if (time_since_damage.asMilliseconds() > 350)
            {
                --health;
                time_since_damage = sf::Time{};
            }
            collisions.erase(collisions.begin() + i);
            --i;
        }
        else if (dynamic_cast<Player*>(other_ptr))
        {
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

int Enemy::random_int(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rand);
}