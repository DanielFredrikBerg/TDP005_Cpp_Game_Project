//
// Created by viktor on 2020-11-24.
//

#ifndef SFML_TEST_GAME_STATE_H
#define SFML_TEST_GAME_STATE_H

#include "state.h"
#include "level.h"

class Game_State : public State
{
public:
    Game_State(std::string const& file_name);

    ~Game_State() = default;

    std::shared_ptr<State> update(sf::Time time) override;

    void draw(sf::RenderWindow & window) override;
private:
    std::shared_ptr<Level> level;
};


#endif //SFML_TEST_GAME_STATE_H
