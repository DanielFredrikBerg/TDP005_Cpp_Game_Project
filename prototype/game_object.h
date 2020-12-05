//
// Created by viktor on 2020-11-25.
//

#ifndef SFML_TEST_GAME_OBJECT_H
#define SFML_TEST_GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Level;

class Game_Object
{
public:
    Game_Object(sf::Sprite & sprite, int animation_frames = 1, double ms_per_frame = 100);

    bool collides_with(Game_Object const& other) const;

    virtual void draw(sf::RenderWindow & window);

    virtual void update(sf::Time const& time, Level & level);

    const sf::Sprite& get_sprite();

protected:
    sf::Sprite sprite;

    int animation_frames;

    int current_frame;

    double ms_per_frame;

    sf::Time animation_timer;

    bool flip_sprite;

    double sqr_dist_to(Game_Object const& other) const;

};


#endif //SFML_TEST_GAME_OBJECT_H
