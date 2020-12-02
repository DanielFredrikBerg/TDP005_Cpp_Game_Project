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

    std::string path{"../Levels/" + file_name + ".csv"};
    std::fstream fs{path};

    if (!fs.is_open())
    {
        std::cout << "failed to open level file" << std::endl;
    }

    //
    sf::Sprite stationary_sprite;
    stationary_sprite.setTexture(instance.tile_sheet);
    stationary_sprite.setScale(3, 3);

    sf::Sprite animated_sprite;
    animated_sprite.setTexture(instance.animation_sheet);
    animated_sprite.setScale(3,3);

    int position{0};
    int value;
    while (fs >> value)
    {
        if (value == 162)
        {
            animated_sprite.setPosition(position % 1152, 48 * (position / 1152));
            animated_sprite.setTextureRect(sf::IntRect{0,0,16,16});
            level -> add_moving(std::make_shared<Player>(animated_sprite), true);
        }
        else if (value != -1)
        {
            stationary_sprite.setPosition(position % 1152, 48 * (position / 1152));
            stationary_sprite.setTextureRect(sf::IntRect{16 * (value % 24), 16 * (value / 24), 16, 16});
            level -> add_stationary(std::make_shared<Game_Object>(stationary_sprite));
        }

        fs.ignore(1);
        position += 48;
    }

    return level;
}



