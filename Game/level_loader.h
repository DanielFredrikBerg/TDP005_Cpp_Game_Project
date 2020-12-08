

#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <set>
#include <fstream>
#include <exception>

#include "level.h"
#include "game_object.h"
#include "player.h"
#include "enemy.h"



class Level_Loader
{
public:

    static std::unique_ptr<Level> load_level(std::string const& file_name);

private:
    Level_Loader();

    static Level_Loader instance;

    sf::FloatRect rect;

    sf::Texture tile_sheet;
    sf::Texture animation_sheet;

    sf::Sprite sprite;
    sf::Sprite animated_sprite;

};


#endif
