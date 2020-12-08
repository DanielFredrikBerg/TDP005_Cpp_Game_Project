

#include "menu_state.h"


Menu_State::Menu_State(Menu_Type type, std::shared_ptr<State> gs)
: game{std::dynamic_pointer_cast<Game_State>(gs)}, selected{0}, type{type}
{
    font.loadFromFile("../Media/font.ttf");

    // create a background Game_State to be drawn behind the menu
    if (game == nullptr)
    {
        game = std::make_shared<Game_State>("level1");
    }

    switch (type)
    {
        case Menu_Type::main:
            menu_items.push_back(Menu_Item{sf::Text{"Start Game", font, 60},
                                           [this]() { return game;}});

            menu_items.push_back(Menu_Item{sf::Text{"Level Select", font, 60},
                                           []() { return std::make_shared<Menu_State>(Menu_Type::levels);}});

            menu_items.push_back(Menu_Item{sf::Text{"Options", font, 60},
                                           [this]() { return shared_from_this();}});

            menu_items.push_back(Menu_Item{sf::Text{"Exit", font, 60},
                                           []() { return nullptr;}});
            break;

        case Menu_Type::pause:
            menu_items.push_back(Menu_Item{sf::Text{"Continue", font, 60},
                                           [this]() { return game;}});

            menu_items.push_back(Menu_Item{sf::Text{"Retry", font, 60},[this]()
            {
                return std::make_shared<Game_State>(game -> get_level_name());
            }});

            menu_items.push_back(Menu_Item{sf::Text{"Main Menu", font, 60},
                                           []() { return std::make_shared<Menu_State>(Menu_Type::main);}});

            menu_items.push_back(Menu_Item{sf::Text{"Exit", font, 60},
                                           []() { return nullptr;}});
            break;

        case Menu_Type::levels:
            // create a menu item for each level in the Levels folder
            for (const auto & entry : std::filesystem::directory_iterator("../Levels"))
            {
                std::string file_name{entry.path().filename().string()};
                // ignore background/foreground files
                if (file_name.find("_bg.csv") == std::string::npos
                    && file_name.find("_fg.csv") == std::string::npos)
                {
                    std::string level_name{file_name.substr(0, file_name.size() - 4)};
                    menu_items.push_back(Menu_Item{sf::Text{level_name, font, 60},
                                                   [level_name]() { return std::make_shared<Game_State>(level_name);}});
                }
            }
            menu_items.push_back(Menu_Item{sf::Text{"Back", font, 60},
                                           []() { return std::make_shared<Menu_State>(Menu_Type::main);}});
            break;
        case Menu_Type::game_over:
            menu_items.push_back(Menu_Item{sf::Text{"Retry", font, 60},[this]()
            {
                return std::make_shared<Game_State>(game -> get_level_name());
            }});

            menu_items.push_back(Menu_Item{sf::Text{"Main Menu", font, 60},
                                           []() { return std::make_shared<Menu_State>(Menu_Type::main);}});
        default:
            break;
    }


}

std::shared_ptr<State> Menu_State::take_user_input(sf::Time time)
{
    delay += time;
    if (delay.asMilliseconds() > 200)
    {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
        {
            return menu_items[selected].action();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            selected = std::max(selected - 1, 0);
            if (type == Menu_Type::levels)
            {
                game = std::make_shared<Game_State>(menu_items[selected].text.getString());
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            selected = std::min(static_cast<unsigned long>(selected + 1), menu_items.size() - 1);
            if (type == Menu_Type::levels && selected + 1 < menu_items.size())
            {
                game = std::make_shared<Game_State>(menu_items[selected].text.getString());
            }
        }
        else
        {
            return shared_from_this();
        }
        delay = sf::Time{};
    }

    return shared_from_this();
}

std::shared_ptr<State> Menu_State::update(sf::Time)
{
    return shared_from_this();
}


void Menu_State::draw(sf::RenderWindow & window)
{
    // draw background Game_State
    game -> draw(window);

    sf::Vector2f view_position = window.getView().getCenter();
    sf::Vector2u window_size = window.getSize();
    double y{view_position.y - window_size.y / 4};

    // draw menu items
    for (auto i{0}; i < menu_items.size(); ++i)
    {
        sf::FloatRect bounds = menu_items[i].text.getLocalBounds();
        menu_items[i].text.setPosition((window_size.x - bounds.width) / 2, y);
        y += bounds.height * 2.0f;

        if (i == selected)
        {
            menu_items[i].text.setFillColor(sf::Color(255, 255, 0));
        }
        else
        {
            menu_items[i].text.setFillColor(sf::Color(255, 255, 255));
        }

        window.draw(menu_items[i].text);
    }


}