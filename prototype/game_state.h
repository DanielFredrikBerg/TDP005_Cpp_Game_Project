//
// Created by viktor on 2020-11-24.
//

#ifndef SFML_TEST_GAME_STATE_H
#define SFML_TEST_GAME_STATE_H

#include <string>
#include <memory>
#include <vector>
#include <functional>

#include "state.h"
#include "menu_state.h"
#include "level.h"
#include "level_loader.h"

class Game_State : public State
{
public:
    Game_State(std::string const& file_name);

    ~Game_State() = default;

    std::shared_ptr<State> update(sf::Time time) override;

    void draw(sf::RenderWindow & window) override;

    std::string get_level_name() const;
private:
    std::shared_ptr<Level> level;

    std::string level_name;
};


#endif //SFML_TEST_GAME_STATE_H
