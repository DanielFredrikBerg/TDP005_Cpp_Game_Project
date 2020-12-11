

#ifndef LEVEL_H
#define LEVEL_H

#include <set>
#include <memory>
#include <SFML/Graphics.hpp>

#include "game_object.h"

class Game_Object; // forward declaration

/*
 * A level in the game.
 */
class Level
{
public:
     /**
      * Default constructor is deleted to prohibit the creation of an empty level.
      */
     Level() = delete;

     /**
      * Create a level consisting of the given objects.
      */
    Level(std::multiset<std::pair<int, std::shared_ptr<Game_Object>>> & game_objects, sf::Vector2f player_pos);


    /**
     * Update each object in a level based on time passed.
     *
     * Return value notifies Game_State if the player has completed or failed the level.
     */
    Update_Result update(sf::Time time);

    /**
     * Draw a level to the screen.
     */
    void draw(sf::RenderWindow & window) const;

    /**
     * Returns every object in a level that the parameter object is colliding with.
     */
    std::vector<std::shared_ptr<Game_Object>> get_collisions(Game_Object & obj) const;

    /**
     * Add an object to the level.
     *
     * Used to add a projectile when a player/enemy shoots.
     */
    void add_object(std::shared_ptr<Game_Object> obj, int draw_priority);

    /**
     * Determines if the lava in the level is rising.
     */
    bool rising_lava;

    /**
     * Position of the player
     */
    sf::Vector2f player_pos;
private:

    /**
     * Every object in the level paired with its draw priority.
     *
     * Objects with a higher priority are drawn in front of objects with a lower priority.
     *
     * Sorted by priority, low -> high.
     */
    std::multiset<std::pair<int, std::shared_ptr<Game_Object>>> game_objects;
};


#endif
