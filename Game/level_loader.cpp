
#include <iostream>
#include "level_loader.h"

using Object_ptrs = std::vector<std::shared_ptr<Game_Object>>;
using Object_ptr = std::shared_ptr<Game_Object>;

Level_Loader Level_Loader::instance;

Level_Loader::Level_Loader()
: tile_sheet{sf::Texture{}}, animation_sheet{sf::Texture{}}
{
    // load sprite textures for non-animated objects
    tile_sheet.loadFromFile("Media/map_tiles.png");
    tile_sheet.setSmooth(false);
    sprite.setTexture(tile_sheet);
    instance.sprite.setScale(3, 3);

    // load sprite textures for animated objects
    animation_sheet.loadFromFile("Media/animation_sheet.png");
    animation_sheet.setSmooth(false);
    animated_sprite.setTexture(animation_sheet);
    instance.animated_sprite.setScale(3, 3);
}

std::unique_ptr<Level> Level_Loader::load_level(std::string const& level_name)
{
    // read file data
    std::string path{"Levels/" + level_name + ".csv"};
    std::fstream fs{path};

    // container for every object in a level
    std::multiset<std::pair<int, std::shared_ptr<Game_Object>>> game_objects;

    // player start position
    sf::Vector2f player_pos;

    /* ---ADD MAIN LAYER--- */
    instance.rect.width = 48;
    instance.rect.height = 48;
    int position{0};
    int value;
    while (fs >> value)
    {
        instance.rect.left = position % constants::window_width;
        instance.rect.top = 48 * (position / constants::window_width);

        // add walking enemy
        if (value == 111)
        {
            instance.rect.width = 42;
            instance.rect.height = 42;
            instance.rect.top += 6;

            instance.animated_sprite.setTextureRect(
                    sf::IntRect{0, 16 * 6, 16, 16});

            game_objects.insert(std::make_pair(4,std::make_shared<Walking_Enemy>(
                    instance.rect, instance.animated_sprite, 3, 48)));

            instance.rect.width = 48;
            instance.rect.height = 48;
        }
        // add jumping enemy
        else if (value == 112)
        {
            instance.rect.width = 40;
            instance.rect.height = 44;
            instance.rect.top += 8;

            instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);

            instance.animated_sprite.setTextureRect(
                    sf::IntRect{0,16 * 4,16,16});

            game_objects.insert(std::make_pair(4,std::make_shared<Enemy>(
                            instance.rect, instance.animated_sprite,2, 96)));

            instance.rect.width = 48;
            instance.rect.height = 48;
        }
        // add flying enemy
        else if (value == 113)
        {
            instance.rect.width = 40;
            instance.rect.height = 40;
            instance.rect.top += 4;

            instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);

            instance.animated_sprite.setTextureRect(
                    sf::IntRect{1, 16 * 5 + 1, 16, 16});

            game_objects.insert(std::make_pair(
                    4,std::make_shared<Flying_Enemy>(
                            instance.rect, instance.animated_sprite,1,96)));

            instance.rect.width = 48;
            instance.rect.height = 48;
        }
        // add Player 1
        else if (value == 135)
        {
            instance.rect.width = 40;
            instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);

            instance.animated_sprite.setTextureRect(
                    sf::IntRect{16, 16, 16, 16});

            std::shared_ptr<Player> p{new Player{instance.rect, instance.animated_sprite}};

            game_objects.insert(std::make_pair(5,
                                               std::make_shared<Player>(instance.rect, instance.animated_sprite)));

            player_pos = sf::Vector2f{instance.rect.left, instance.rect.top};
            instance.rect.width = 48;
        }
        // add platform
        else if (value < 312 && value > 0 && value != 136)
        {
            instance.sprite.setPosition(instance.rect.left, instance.rect.top);

            instance.sprite.setTextureRect(sf::IntRect{
                16 * (value % 24), 16 * (value / 24), 16, 16});

            game_objects.insert(std::make_pair(
                    4,std::make_shared<Textured_Object>(instance.rect, instance.sprite)));
        }

        fs.ignore(1);
        position += 48;
    }
    fs.close();


    /*  ---ADD LAVA--- */
    instance.rect.width = 96;
    instance.rect.height = 96;

    // add animated lava
    for (int i{0}; i < 12; ++i)
    {
        instance.rect.left = position % constants::window_width;
        instance.rect.top = 48 * (position / constants::window_width);
        instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
        instance.animated_sprite.setTextureRect(
                sf::IntRect{(i % 6) * 32, 16 * 9, 32, 32});
        game_objects.insert(std::make_pair(
                10,std::make_shared<Lava>(instance.rect, instance.animated_sprite, true)));
        position += 96;
    }
    // add large non-animated lava rectangle
    instance.rect = sf::FloatRect{0, 48.0f * (position / constants::window_width),
                                  constants::window_width, constants::window_height};
    instance.sprite.setTextureRect(sf::IntRect{16 * 10, 16 * 6, 16, 16});
    instance.sprite.setScale(72,72);
    game_objects.insert(std::make_pair(
            10,std::make_shared<Lava>(instance.rect, instance.sprite, false)));
    instance.sprite.setScale(3,3);




    /* ---ADD BACKGROUND--- */
    path = "Levels/" + level_name + "_bg.csv";
    fs.open(path);

    instance.rect.width = 0;
    instance.rect.height = 0;

    if (fs.is_open())
    {
        position = 0;

        while (fs >> value)
        {
            instance.rect.left = position % constants::window_width;
            instance.rect.top = 48 * (position / constants::window_width);

            if (value > 312 && value < 480) {
                // add lava fall
                if (value == 384) {
                    instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
                    instance.animated_sprite.setTextureRect(sf::IntRect{
                        (position / constants::window_width) % 3,16 * 7, 16, 16});

                    game_objects.insert(std::make_pair(
                            2,std::make_shared<Animated_Object>(instance.rect, instance.animated_sprite)));
                }
                // add torch
                else if (value == 432)
                {
                    instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
                    instance.animated_sprite.setTextureRect(sf::IntRect{
                            (position / constants::window_width) % 3,
                             16 * 13, 16, 16});

                    game_objects.insert(std::make_pair(
                            2,std::make_shared<Animated_Object>(instance.rect, instance.animated_sprite)));
                }
                // misc background
                else
                {
                    instance.sprite.setPosition(instance.rect.left, instance.rect.top);
                    instance.sprite.setTextureRect(sf::IntRect{
                        16 * (value % 24),16 * (value / 24), 16, 16});

                    game_objects.insert(std::make_pair(
                            2, std::make_shared<Textured_Object>(instance.rect, instance.sprite)));
                }
            }

            fs.ignore(1);
            position += 48;
        }
    }
    fs.close();


    /* ---ADD FOREGROUND--- */
    path = "Levels/" + level_name + "_fg.csv";
    fs.open(path);

    if (fs.is_open())
    {
        position = 0;
        while (fs >> value)
        {
            instance.rect.left = position % constants::window_width;
            instance.rect.top = 48 * (position / constants::window_width);

            if (value > 480)
            {
                instance.sprite.setPosition(instance.rect.left, instance.rect.top);

                instance.sprite.setTextureRect(sf::IntRect{
                    16 * (value % 24),16 * (value / 24), 16, 16});

                game_objects.insert(std::make_pair(
                        8, std::make_shared<Textured_Object>(instance.rect, instance.sprite)));
            }

            fs.ignore(1);
            position += 48;
        }
    }
    fs.close();

    return std::make_unique<Level>(game_objects, player_pos);
}



