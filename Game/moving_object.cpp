
#include <iostream>
#include "moving_object.h"
#include "level.h"


void Moving_Object::update(const sf::Time &time, Level &level)
{

    sprite.move(velocity.x * time.asSeconds(), velocity.y * time.asSeconds());

    // collision with borders
    if (sprite.getPosition().x < 0)
    {
        sprite.setPosition(0, sprite.getPosition().y);
        velocity.x = 0;
    }
    else if (sprite.getPosition().x > 1152 - sprite.getGlobalBounds().width)
    {
        sprite.setPosition(1152 - sprite.getGlobalBounds().width, sprite.getPosition().y);
        velocity.x = 0;
    }

    // collision with stationary objects
    handle_collision_with_stationary(level);

    Game_Object::update(time, level);


}


void Moving_Object::handle_collision_with_stationary(Level & level)
{
    // find all collisions with stationary objects
    auto collisions{level.get_collisions_stationary(*this)};

    // find distance to objects in collision
    std::vector<std::pair<Game_Object, double>> collision_distances;
    for (auto & other : collisions)
    {
        collision_distances.push_back(std::make_pair(*other, sqr_dist_to(*other)));
    }

    // sort collisions by distance
    std::sort(collision_distances.begin(), collision_distances.end(),
              [] (std::pair<Game_Object, double> const& a, std::pair<Game_Object, double> const& b)
              {
                  return a.second < b.second;
              });

    // handle collisions in order of distance, closest first
    for (auto & other : collision_distances)
    {
        // check if there still is a collision
        if (!collides_with(other.first))
        {
            continue;
        }

        sf::Sprite o_sprite{other.first.get_sprite()};

        double x_diff = abs(sprite.getPosition().x -  o_sprite.getPosition().x);
        double y_diff = abs(sprite.getPosition().y -  o_sprite.getPosition().y);

        // move object the shortest way out of the collision
        if ((x_diff - sprite.getGlobalBounds().width) > (y_diff - sprite.getGlobalBounds().height))
        {

            if (o_sprite.getPosition().x < sprite.getPosition().x)
            {
                // collision to the left
                velocity.x = std::max(0.0f, velocity.x);
                sprite.setPosition(o_sprite.getPosition().x + o_sprite.getGlobalBounds().width, sprite.getPosition().y);

            }
            else
            {
                // collision to the right
                velocity.x = std::min(0.0f, velocity.x);
                sprite.setPosition(o_sprite.getPosition().x - sprite.getGlobalBounds().width, sprite.getPosition().y);
            }
        }
        else
        {
            if (o_sprite.getPosition().y < sprite.getPosition().y)
            {
                // collision from above
                velocity.y = std::max(0.0f,velocity.y);
                sprite.setPosition(sprite.getPosition().x, o_sprite.getPosition().y + sprite.getGlobalBounds().height);
            }
            else
            {
                // collision from below
                velocity.y = std::min(0.0f, velocity.y);
                sprite.setPosition(sprite.getPosition().x, o_sprite.getPosition().y - sprite.getGlobalBounds().height );
            }
        }

    }
}