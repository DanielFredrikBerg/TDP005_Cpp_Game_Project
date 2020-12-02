//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_GAME_OBJECT_H
#define SFML_TEST_GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Game_Object
{
public:
    Game_Object(sf::Sprite & sprite, int width = 48, int height = 48);

    bool collides_with(Game_Object const& other) const;

    virtual void draw(sf::RenderWindow & window);

    sf::Vector2f get_position();

protected:
    sf::Sprite sprite;

    int width;

    int height;

    int animation_frames{1};

    int current_frame{0};

    double ms_per_frame{100};

    sf::Time animation_timer;

    bool flip_sprite{false};

    double sqr_dist_to(Game_Object const& other) const;

    double x_dist_to(Game_Object const& other) const;

    double y_dist_to(Game_Object const& other) const;
};


#endif //SFML_TEST_GAME_OBJECT_H
