//
// Created by viktor on 2020-11-25.
//

#include <iostream>
#include "moving_object.h"
#include "level.h"

Moving_Object::Moving_Object(sf::Sprite & sprite, int width, int height)
: Game_Object{sprite, width, height}, texture_rect{sprite.getTextureRect()}
{}


void Moving_Object::update(const sf::Time &time, Level &level)
{

    sprite.move(velocity.x * time.asSeconds(), velocity.y * time.asSeconds());

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

    // flip sprite
    if (flip_sprite)
    {
        sf::IntRect new_text_rect{texture_rect};
        new_text_rect.left += 16;
        new_text_rect.width *= -1;
        sprite.setTextureRect(new_text_rect);
    }
    else
    {
        sf::IntRect new_text_rect{texture_rect};
        sprite.setTextureRect(new_text_rect);
    }
}


void Moving_Object::handle_collision_with_stationary(Level & level)
{
    // find all collisions with stationary objects
    auto collisions{level.get_collisions_stationary(*this)};

    // find distance to objects in collision
    std::vector<std::pair<Game_Object, double>> collision_distances;
    for (auto & i : collisions)
    {
        collision_distances.push_back(std::make_pair(*i, sqr_dist_to(*i)));
    }

    // sort collisions by distance
    std::sort(collision_distances.begin(), collision_distances.end(),
              [] (std::pair<Game_Object, double> const& a, std::pair<Game_Object, double> const& b)
              {
                  return a.second < b.second;
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
                // collision to the left
                sprite.setPosition(sprite.getPosition().x + (width - x_diff), sprite.getPosition().y);

            }
            else
            {
                // collision to the right
                sprite.setPosition(sprite.getPosition().x - (width + x_diff), sprite.getPosition().y);
            }
        }
        else
        {
            if (y_diff > 0)
            {
                // collision from above
                velocity.y = std::max(0.0f,velocity.y);
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + (height - y_diff));
            }
            else
            {
                // collision from below
                velocity.y = std::min(0.0f, velocity.y);
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (height + y_diff));
            }
        }

    }
}