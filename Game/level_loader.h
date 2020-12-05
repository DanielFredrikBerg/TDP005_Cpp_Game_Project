

#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <fstream>

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

    sf::Texture tile_sheet;
    sf::Texture animation_sheet;

    std::map<std::string, std::unique_ptr<Level>> loaded_levels;
};


#endif //SFML_TEST_LEVEL_LOADER_H
