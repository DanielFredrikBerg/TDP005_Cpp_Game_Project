cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 17)

set(SFML_MODULES graphics window system)

foreach(i ${SFML_MODULES})
    list(APPEND SFML_LIBRARIES "sfml-${i}")
endforeach(i)

set(SOURCE_FILES main.cpp)

add_executable(game main.cpp state.cpp state.h game_state.cpp game_state.h level.cpp level.h menu_state.cpp menu_state.h game_object.h moving_object.cpp moving_object.h enemy.cpp enemy.h projectile.cpp projectile.h player.cpp player.h movement_behavior.cpp movement_behavior.h attack_behavior.cpp attack_behavior.h behavior.cpp behavior.h level_loader.cpp level_loader.h textured_object.h textured_object.cpp common.h animated_object.cpp animated_object.h lava.cpp lava.h)

target_link_libraries(game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})