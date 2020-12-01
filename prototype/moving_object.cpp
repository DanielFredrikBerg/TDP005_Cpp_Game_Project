//
// Created by viktor on 2020-11-25.
//

#include "moving_object.h"
#include "level.h"


void Moving_Object::update(const sf::Time &time, Level &level)
{
    // apply gravity
    velocity.y += 1600 * time.asSeconds();

    // collision with borders
    if (sprite.getPosition().x < 0)
    {
        sprite.setPosition(0, sprite.getPosition().y);
        velocity.x = 0;
    }

    if (sprite.getPosition().x > 1152 - width)
    {
        sprite.setPosition(1152 - width, sprite.getPosition().y);
        velocity.x = 0;
    }

    // collision with stationary objects
    handle_collision_with_stationary(level);
}


void Moving_Object::handle_collision_with_stationary(Level & level)
{
    // find all collisions with stationary objects
    auto collisions{level.find_collisions_with_stationary(*this)};

    // find distance to objects in collision
    std::vector<std::pair<Game_Object, double>> collision_distances;
    for (auto & i : collisions)
    {
        collision_distances.push_back(std::make_pair(*i, sqr_dist_to(*i)));
    }

    // reverse-sort collisions by distance
    std::sort(collision_distances.begin(), collision_distances.end(),
              [] (std::pair<Game_Object, double> const& a, std::pair<Game_Object, double> const& b)
              {
                  return a.second > b.second;
              });

    // handle collisions in order of distance, closest first
    for (auto & i : collision_distances)
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
            velocity.x = 0;
            if (x_diff > 0)
            {
                // collision to the right
                sprite.setPosition(sprite.getPosition().x + (width - x_diff), sprite.getPosition().y);

            }
            else
            {
                // collision to the left
                sprite.setPosition(sprite.getPosition().x - (width + x_diff), sprite.getPosition().y);
            }
        }
        else
        {
            velocity.y = 0;
            if (y_diff > 0)
            {
                // collision from above
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + (height - y_diff));
            }
            else
            {
                // collision from below
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (height + y_diff));
            }
        }

    }
}