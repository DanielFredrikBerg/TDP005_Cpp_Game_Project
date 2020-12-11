

#ifndef PLAYER_H
#define PLAYER_H

#include <utility>
#include <algorithm>

#include "moving_object.h"
#include "game_object.h"
#include "level.h"
#include "enemy.h"
#include "projectile.h"
#include "lava.h"
#include "common.h"


/**
 * The playable character of the game.
 */
class Player : public Moving_Object
{
public:
    /**
     * Create a player object with a bounding rectangle, and a textured shape.
     */
    Player(sf::FloatRect & rect, sf::Sprite & sprite);

    /**
     * Update player based on keyboard input, apply gravity,
     * and then move the player and call resolve_collisions.
     * Returns false if health is zero.
     */
    Update_Result update(sf::Time const& time, Level & level) override;


    /**
     * Update window view and player health bar positions,
     * then animate & draw the player.
     */
    void draw(sf::RenderWindow & window) override;

    /**
     * Handles collisions between a player and other moving objects,
     *  then handle collisions between player and platforms + window borders.
     */
    void resolve_collisions(std::vector<std::shared_ptr<Game_Object>> collisions) override;

    /**
     * Determines which frame of an animation will be drawn.
     */
    void animate() override;

private:
    /**
     *  Time since last jump.
     */
    sf::Time time_since_jump;

    /**
     *  Time since last time the player took damage.
     */
    sf::Time time_since_damage;

    /**
     * Time since last time the player fired a projectile.
     */
    sf::Time time_since_fire;

    /**
     * Player health, [0,3].
     * Game ends if health is 0.
     */
    int health;

    /**
     * Health indicator sprite for a player.
     */
    sf::Sprite health_bar;

    /**
     *  Decide player action based on keyboard input.
     */
    void handle_input(sf::Time const& time, Level & level);

    /**
     * Fire a projectile.
     */
    void fire(Level & level, bool direction);
};


#endif
