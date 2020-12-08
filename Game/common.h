

#ifndef COMMON_H
#define COMMON_H

/**
 * Defines global constants.
 */
namespace constants
{
    double const gravity_const{0.007};

    double const player_invul_const{1618};

    int const window_width{1152};
    int const window_height{960};

}

/**
 * Specifies menu types for the Menu_State class.
 */
enum class Menu_Type : int
{
    main, pause, levels, options, game_over
};


/**
 * Specifies what animation to use for a Textured_Object
 */
enum class Animation_State : int
{
    none, bg_object
};

#endif
