//
// Created by viktor on 2020-12-01.
//


#include <iostream>
#include "level_loader.h"

Level_Loader Level_Loader::instance;

Level_Loader::Level_Loader()
: tile_sheet{sf::Texture{}}, animation_sheet{sf::Texture{}}
{
    tile_sheet.loadFromFile("../Media/map_tiles.png");
    animation_sheet.loadFromFile("../Media/animation_sheet.png");
}

std::unique_ptr<Level> Level_Loader::load_level(std::string const& file_name)
{

    if (instance.loaded_levels.find(file_name) != instance.loaded_levels.end())
    {
        std::unique_ptr<Level> level_ptr{move(instance.loaded_levels[file_name])};
        instance.loaded_levels.erase(file_name);
        return level_ptr;
    }

    std::unique_ptr<Level> level = std::make_unique<Level>();

    std::string path{"Levels/" + file_name + ".csv"};
    std::fstream fs{path};

    if (!fs.is_open())
    {
        std::cout << "failed to open level file" << std::endl;
    }

    return level;
}



