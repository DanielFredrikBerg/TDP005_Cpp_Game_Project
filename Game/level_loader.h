

#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <set>
#include <fstream>
#include <exception>

#include "level.h"
#include "game_object.h"
#include "player.h"
#include "enemy.h"
#include "lava.h"


/**
 * Static class for loading a level from file.
 */
class Level_Loader
{
public:

    /**
     * Creates and returns the level with the given level name.
     */
    static std::unique_ptr<Level> load_level(std::string const& level_name);

private:
    /**
     *
     */
    Level_Loader();

    /**
     *
     */
    static Level_Loader instance;

    sf::FloatRect rect;

    sf::Sprite sprite;
    sf::Sprite animated_sprite;

    /**
     * Sprite sheet for non-animated objects.
     */
    sf::Texture tile_sheet;

    /**
     * Sprite sheet for animated objects.
     */
    sf::Texture animation_sheet;

};


#endif
