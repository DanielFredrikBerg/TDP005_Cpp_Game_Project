cmake_minimum_required(VERSION 3.17)
project(sfml_test)

set(CMAKE_CXX_STANDARD 17)

set(SFML_MODULES graphics window system)

foreach(i ${SFML_MODULES})
    list(APPEND SFML_LIBRARIES "sfml-${i}")
endforeach(i)

set(SOURCE_FILES main.cpp)

add_executable(sfml_test main.cpp state.cpp state.h main_menu_state.cpp main_menu_state.h game_state.cpp game_state.h game_over_state.cpp game_over_state.h pause_menu_state.cpp pause_menu_state.h)

target_link_libraries(sfml_test ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})