

#ifndef LAVA_H
#define LAVA_H

#include "animated_object.h"
#include "level.h"

/**
 * Animated lava flow that follows the player character up through a level.
 * Kills the player on touch.
 */
class Lava : public Animated_Object
{
public:
    Lava(sf::FloatRect & rect, sf::Sprite & sprite, bool animated);

    /**
     * Raise the lava level, if it is active.
     */
    Update_Result update(sf::Time const& time, Level & level) override;

    /**
     * Determines which frame of an animation will be drawn.
     */
    void animate() override;
private:

    sf::Time active;

    bool animated;
};


#endif

