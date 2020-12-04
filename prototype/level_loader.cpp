//
// Created by viktor on 2020-12-01.
//


#include <iostream>
#include "level_loader.h"

using Object_ptrs = std::vector<std::shared_ptr<Game_Object>>;
using Object_ptr = std::shared_ptr<Game_Object>;

Level_Loader Level_Loader::instance;

Level_Loader::Level_Loader()
: tile_sheet{sf::Texture{}}, animation_sheet{sf::Texture{}}
{
    tile_sheet.loadFromFile("../Media/map_tiles.png");
    animation_sheet.loadFromFile("../Media/animation_sheet.png");
}

std::unique_ptr<Level> Level_Loader::load_level(std::string const& file_name)
{
    /*
    if (instance.loaded_levels.find(file_name) != instance.loaded_levels.end())
    {
        std::unique_ptr<Level> level_ptr{move(instance.loaded_levels[file_name])};
        instance.loaded_levels.erase(file_name);
        return level_ptr;
    } */

    std::string path{"../Levels/" + file_name + ".csv"};
    std::fstream fs{path};

    if (!fs.is_open())
    {
        std::cout << "failed to open level file" << std::endl;
    }

    Object_ptrs stationary_objects;
    Object_ptrs moving_objects;
    Object_ptr player_1;

    //
    sf::Sprite stationary_sprite;
    stationary_sprite.setTexture(instance.tile_sheet);
    stationary_sprite.setScale(3, 3);

    sf::Sprite moving_sprite;
    moving_sprite.setTexture(instance.animation_sheet);
    moving_sprite.setScale(3, 3);

    int position{0};
    int value;
    while (fs >> value)
    {


        // add walking enemy
        if (value == 159)
        {
            moving_sprite.setPosition(position % 1152, 48 * (position / 1152));
            moving_sprite.setTextureRect(sf::IntRect{0, 16 * 6, 16, 16});
            moving_objects.push_back(std::make_shared<Enemy>(moving_sprite));
        }
        // add jumping enemy
        else if (value == 160)
        {
            moving_sprite.setPosition(position % 1152, 48 * (position / 1152));
            moving_sprite.setTextureRect(sf::IntRect{0, 16 * 4, 16, 16});
            moving_objects.push_back(std::make_shared<Enemy>(moving_sprite));
        }
        // add flying enemy
        else if (value == 161)
        {
            moving_sprite.setPosition(position % 1152, 48 * (position / 1152));
            moving_sprite.setTextureRect(sf::IntRect{0, 16 * 5, 16, 16});
            moving_objects.push_back(std::make_shared<Enemy>(moving_sprite));
        }
        // add Player 1
        else if (value == 162)
        {
            // create health bar
            sf::Sprite health_bar;
            health_bar.setTexture(instance.animation_sheet);
            health_bar.setPosition(position % 1152 + 8, 48 * (position / 1152) - 24);
            health_bar.setTextureRect(sf::IntRect{0,16 * 18,24,16});
            health_bar.setScale(1.5, 1.5);

            // add player 1
            moving_sprite.setPosition(position % 1152, 48 * (position / 1152));
            moving_sprite.setTextureRect(sf::IntRect{14, 16, 14, 16});
            player_1 = std::make_shared<Player>(moving_sprite, health_bar);
        }
        else if (value > 400)
        {
            // BACKGROUND
        }
        else if (value > 800)
        {
            // FOREGROUND
        }
        else if (value != -1)
        {
            stationary_sprite.setPosition(position % 1152, 48 * (position / 1152));
            stationary_sprite.setTextureRect(sf::IntRect{16 * (value % 24), 16 * (value / 24), 16, 16});
            stationary_objects.push_back(std::make_shared<Game_Object>(stationary_sprite));
        }

        fs.ignore(1);
        position += 48;
    }

    std::unique_ptr<Level> level = std::make_unique<Level>(stationary_objects, moving_objects, player_1);

    return level;
}



