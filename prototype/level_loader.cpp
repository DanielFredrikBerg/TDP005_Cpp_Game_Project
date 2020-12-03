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


        // add walking enemy
        if (value == 159)
        {
            animated_sprite.setPosition(position % 1152, 48 * (position / 1152));
            animated_sprite.setTextureRect(sf::IntRect{0,16 * 6,16,16});
            level -> add_moving(std::make_shared<Enemy>(animated_sprite));
        }
        // add jumping enemy
        else if (value == 160)
        {
            animated_sprite.setPosition(position % 1152, 48 * (position / 1152));
            animated_sprite.setTextureRect(sf::IntRect{0,16 * 4,16,16});
            level -> add_moving(std::make_shared<Enemy>(animated_sprite));
        }
        // add flying enemy
        else if (value == 161)
        {
            animated_sprite.setPosition(position % 1152, 48 * (position / 1152));
            animated_sprite.setTextureRect(sf::IntRect{0,16 * 5,16,16});
            level -> add_moving(std::make_shared<Enemy>(animated_sprite));
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
            animated_sprite.setPosition(position % 1152, 48 * (position / 1152));
            animated_sprite.setTextureRect(sf::IntRect{16,16,16,16});
            level -> add_moving(std::make_shared<Player>(animated_sprite, 48, 48, health_bar), true);
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
            level -> add_stationary(std::make_shared<Game_Object>(stationary_sprite));
        }

        fs.ignore(1);
        position += 48;
    }



    return level;
}



