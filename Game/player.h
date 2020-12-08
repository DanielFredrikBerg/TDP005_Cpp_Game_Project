

#ifndef PLAYER_H
#define PLAYER_H

#include <utility>
#include <algorithm>

#include "moving_object.h"
#include "game_object.h"
#include "level.h"
#include "enemy.h"
#include "projectile.h"
#include "common.h"


/**
 * The playable character of the game.
 */
class Player : public Moving_Object
{
public:
    /**
     *
     */
    Player(sf::FloatRect & rect, sf::Sprite & sprite);

    void update(sf::Time const& time, Level & level) override;

    void draw(sf::RenderWindow & window) override;

    void resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions) override;

    void animate() override;

private:
    sf::Time time_since_jump;

    sf::Time time_since_damage;

    int health;

    /**
     *
     */
    bool flip_sprite;

    sf::Sprite health_bar;

    void handle_input(sf::Time const& time);
};


#endif
