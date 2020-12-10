

#include <iostream>
#include "level.h"


Level::Level(std::multiset<std::pair<int, std::shared_ptr<Game_Object>>> & game_objects, sf::FloatRect* player_rect)
: game_objects{game_objects}, player_rect{player_rect}, rising_lava{false}
{}


Update_Result Level::update(sf::Time time)
{
    // update the state of each game object
    for (auto it{game_objects.begin()}; it != game_objects.end();)
    {
        Update_Result result{it -> second -> update(time, *this)};

        if (result == Update_Result::remove_object)
        {
            std::cout << game_objects.size() << std::endl;

            it = game_objects.erase(it);

            std::cout << game_objects.size() << std::endl;
        }
        else
        {
            ++it;
        }

        if (result == Update_Result::game_over || result == Update_Result::level_complete)
        {
            return result;
        }
    }
    return Update_Result::none;
}

void Level::draw(sf::RenderWindow & window) const
{
    // update window view position
    sf::View currentView = window.getView();
    currentView.setCenter(constants::window_width / 2, player_rect -> top);
    window.setView(currentView);

    // draw game_objects in order of draw priority
    for (auto & obj : game_objects)
    {
        obj.second -> draw(window);
    }
}

std::vector<std::shared_ptr<Game_Object>> Level::get_collisions(Game_Object & obj) const
{
    std::vector<std::shared_ptr<Game_Object>> collisions;
    for (auto & other : game_objects)
    {
        if (&obj != other.second.get() && obj.rect.intersects(other.second->rect))
        {
            collisions.push_back(other.second);
        }
    }
    return collisions;
}

void Level::add_object(std::shared_ptr<Game_Object> obj, int draw_priority)
{
    game_objects.insert(std::make_pair(draw_priority, obj));
}


