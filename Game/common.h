

#ifndef COMMON_H
#define COMMON_H

/**
 * Defines global constants.
 */
namespace constants
{
    float const gravity_const{0.006};

    double const player_invul_const{1618};

    int const window_width{1152};
    int const window_height{960};

}

/**
 * Specifies menu types for the Menu_State class.
 */
enum class Menu_Type : int
{
    main, pause, levels, options, level_complete, game_over
};

/**
 * Return type for Game_Object update function.
 * Specifies the result of an update function call.
 */
enum class Update_Result : int
{
    none, remove_object, level_complete, game_over
};


#endif
