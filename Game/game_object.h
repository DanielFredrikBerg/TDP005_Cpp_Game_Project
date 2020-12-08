
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

#include "common.h"

class Level; // forward declaration

/**
 * Abstract base class for every object a level contains.
 */
class Game_Object
{
public:
    /**
     * Create an game object with a bounding rectangle.
     */
    Game_Object(sf::FloatRect rect)
    : rect{rect}
    {}

    /**
     * Abstract classes have a virtual destructor.
     */
    virtual ~Game_Object() = default;

    /**
     * Update the state of an object based on time.
     * Returns false if the object is to be deleted.
     */
    virtual Update_Result update(sf::Time const& time, Level & level) = 0;

    /**
     * Draw an object to the screen.
     */
    virtual void draw(sf::RenderWindow & window) = 0;


    /**
     * Bounding rectangle for an object.
     * Contains x,y coordinates, width, and height.
     */
    sf::FloatRect rect;
};


#endif
