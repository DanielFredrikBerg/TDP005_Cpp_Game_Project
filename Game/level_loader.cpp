
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
    sprite.setTexture(tile_sheet);
    instance.sprite.setScale(3, 3);

    // load sprite textures for animated objects
    animation_sheet.loadFromFile("Media/animation_sheet.png");
    animated_sprite.setTexture(animation_sheet);
    instance.animated_sprite.setScale(3, 3);


}

std::unique_ptr<Level> Level_Loader::load_level(std::string const& file_name)
{
    // read file data
    std::string path{"Levels/" + file_name + ".csv"};
    std::fstream fs{path};

    // container for every object in a level
    std::multiset<std::pair<int, std::shared_ptr<Game_Object>>> game_objects;

    // set rectangle default width/height
    instance.rect.width = 48;
    instance.rect.height = 48;

    // add main layer
    int position{0};
    int value;
    while (fs >> value)
    {
        instance.rect.left = position % constants::window_width;
        instance.rect.top = 48 * (position / constants::window_width);

        // add walking enemy
        if (value == 111)
        {
            instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
            instance.animated_sprite.setTextureRect(sf::IntRect{0, 16 * 6, 16, 16});
            game_objects.insert(std::make_pair(
                    4,std::make_shared<Enemy>(instance.rect, instance.animated_sprite)));
        }
        // add jumping enemy
        else if (value == 112)
        {
            instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
            instance.animated_sprite.setTextureRect(sf::IntRect{0, 16 * 4, 16, 16});
            game_objects.insert(std::make_pair(
                    4,std::make_shared<Enemy>(instance.rect, instance.animated_sprite)));
        }
        // add flying enemy
        else if (value == 113)
        {
            instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
            instance.animated_sprite.setTextureRect(
                    sf::IntRect{0, 16 * 5, 16, 16});
            game_objects.insert(std::make_pair(
                    4,std::make_shared<Enemy>(instance.rect, instance.animated_sprite)));
        }
        // add Player 1
        else if (value == 135)
        {
            instance.rect.width = 34;
            instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
            instance.animated_sprite.setTextureRect(
                    sf::IntRect{16, 16, 16, 16});
            game_objects.insert(
                    std::make_pair(5,std::make_shared<Player>(instance.rect, instance.animated_sprite)));
            instance.rect.width = 48;
        }
        else if (value < 312 && value > 0)
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
    instance.rect.width = 0;
    instance.rect.height = 0;

    /* add lava
    position -= 24 * 48;
    instance.animated_shape.setTextureRect(sf::IntRect{
        14, 16 * 9, 32, 32});

    for (int i{0}; i < 12; ++i)
    {
        instance.rect.left = position % constants::window_width;
        instance.rect.top = 48 * (position / constants::window_width);

        lava.push_back(std::make_shared<Game_Object>(moving_sprite, 6, 300, i % 6));
        position += 96;
    }
    stationary_sprite.setPosition(position % 1152, 48 * (position / 1152));
    stationary_sprite.setTextureRect(sf::IntRect{16 * 10, 16 * 6, 16, 16});
    stationary_sprite.setScale(72,72);
    lava.push_back(std::make_shared<Game_Object>(stationary_sprite));
    stationary_sprite.setScale(3,3); */

    // add background
    path = "Levels/" + file_name + "_bg.csv";
    fs.open(path);

    if (fs.is_open())
    {
        position = 0;
        while (fs >> value)
        {
            instance.rect.left = position % constants::window_width;
            instance.rect.top = 48 * (position / constants::window_width);

            if (value > 312 && value < 480) {
                if (value == 384) {
                    instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
                    instance.animated_sprite.setTextureRect(sf::IntRect{
                        (position / constants::window_width) % 3,16 * 7, 16, 16});

                    game_objects.insert(std::make_pair(
                            2,std::make_shared<Animated_Object>(instance.rect, instance.animated_sprite)));
                }
                else if (value == 432)
                {
                    instance.animated_sprite.setPosition(instance.rect.left, instance.rect.top);
                    instance.animated_sprite.setTextureRect(sf::IntRect{
                            (position / constants::window_width) % 3,16 * 13, 16, 16});

                    game_objects.insert(std::make_pair(
                            2,std::make_shared<Animated_Object>(instance.rect, instance.animated_sprite)));
                }
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


    // add foreground
    path = "Levels/" + file_name + "_fg.csv";
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
                instance.sprite.setTextureRect(sf::IntRect{16 * (value % 24),
                                                          16 * (value / 24), 16, 16});
                game_objects.insert(std::make_pair(8,
                                                   std::make_shared<Textured_Object>(instance.rect, instance.sprite)));
            }

            fs.ignore(1);
            position += 48;
        }
    }
    fs.close();

    return std::make_unique<Level>(game_objects);
}



