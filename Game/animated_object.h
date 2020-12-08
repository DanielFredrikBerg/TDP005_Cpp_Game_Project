

#ifndef ANIMATED_OBJECT_H
#define ANIMATED_OBJECT_H

#include "textured_object.h"

/**
 * A textured object that is animated.
 */
class Animated_Object : public Textured_Object
{
public:
    /**
     * Create an animated object with a bounding rectangle, a textured shape, and an animation state.
     */
    Animated_Object(sf::FloatRect & rect, sf::Sprite & sprite, int frame = 0);

    /**
     * Advance the animation timer and call animate.
     */
    void update(sf::Time const& time, Level & level) override;

    /**
     * Determines which frame of an animation will be drawn.
     */
    virtual void animate();

protected:
    /**
     * Time since an animation updated.
     */
    sf::Time animation_timer;

    /**
     * The current frame of an animation.
     */
    int current_frame;
};


#endif
