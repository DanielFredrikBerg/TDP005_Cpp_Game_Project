//
// Created by viktor on 2020-11-24.
//

#include "level.h"



Level::Level()
: sprite_sheet{sf::Texture{}}
{
    sprite_sheet.loadFromFile("../Media/environment-tiles.png");
    load_level();
}


void Level::draw(sf::RenderWindow & window)
{
    sf::Sprite s{};
    s.setTexture(sprite_sheet);
    s.setScale(2.7,2.7);
    window.draw(s);

    for (Game_Object * obj : stationary_objects)
    {
        obj -> draw(window);
    }

    for (auto & obj : moving_objects)
    {
        obj -> draw(window);
    }

}

/* TEMPORARY FUNCTION FOR CREATING A TEST LEVEL
 * TODO: create a singleton class that loads and saves levels
 */
void Level::load_level()
{
    player_texture.loadFromFile("../Media/player.png");

    sf::Sprite player_sprite;
    player_sprite.setScale(2.7,2.7);
    player_sprite.setTextureRect(sf::IntRect{0,0,16,16});
    player_sprite.setTexture(player_texture);

    moving_objects.push_back(std::make_unique<Player>(player_sprite));


}

