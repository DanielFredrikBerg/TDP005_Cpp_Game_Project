
#ifndef STATE_H
#define STATE_H

#include <memory>
#include <SFML/Graphics.hpp>

class State : public std::enable_shared_from_this<State>
{
public:
    /**
     * Default constructor.
     */
    State() = default;

    /**
     * Abstract classes have a virtual destructor.
     */
    virtual ~State() = default;

    /*
    * Called to update this object based on user action.
    * Can result in a state change between Game_State and Menu_State
    */
    virtual std::shared_ptr<State> update(sf::Time time) = 0;

    /*
     * Called to draw to the screen.
     */
    virtual void draw(sf::RenderWindow & window) = 0;

    /**
     * Run a state, handling state-switches, until completion.
     */
    static void run(sf::RenderWindow & window, std::shared_ptr<State> state);


};


#endif
