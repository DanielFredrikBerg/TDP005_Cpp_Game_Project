# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/viktor/CLionProjects/tdp005/prototype

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sfml_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml_test.dir/flags.make

CMakeFiles/sfml_test.dir/main.cpp.o: CMakeFiles/sfml_test.dir/flags.make
CMakeFiles/sfml_test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml_test.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_test.dir/main.cpp.o -c /home/viktor/CLionProjects/tdp005/prototype/main.cpp

CMakeFiles/sfml_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_test.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viktor/CLionProjects/tdp005/prototype/main.cpp > CMakeFiles/sfml_test.dir/main.cpp.i

CMakeFiles/sfml_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_test.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viktor/CLionProjects/tdp005/prototype/main.cpp -o CMakeFiles/sfml_test.dir/main.cpp.s

CMakeFiles/sfml_test.dir/game.cpp.o: CMakeFiles/sfml_test.dir/flags.make
CMakeFiles/sfml_test.dir/game.cpp.o: ../game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfml_test.dir/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_test.dir/game.cpp.o -c /home/viktor/CLionProjects/tdp005/prototype/game.cpp

CMakeFiles/sfml_test.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_test.dir/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viktor/CLionProjects/tdp005/prototype/game.cpp > CMakeFiles/sfml_test.dir/game.cpp.i

CMakeFiles/sfml_test.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_test.dir/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viktor/CLionProjects/tdp005/prototype/game.cpp -o CMakeFiles/sfml_test.dir/game.cpp.s

CMakeFiles/sfml_test.dir/game_state.cpp.o: CMakeFiles/sfml_test.dir/flags.make
CMakeFiles/sfml_test.dir/game_state.cpp.o: ../game_state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfml_test.dir/game_state.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_test.dir/game_state.cpp.o -c /home/viktor/CLionProjects/tdp005/prototype/game_state.cpp

CMakeFiles/sfml_test.dir/game_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_test.dir/game_state.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viktor/CLionProjects/tdp005/prototype/game_state.cpp > CMakeFiles/sfml_test.dir/game_state.cpp.i

CMakeFiles/sfml_test.dir/game_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_test.dir/game_state.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viktor/CLionProjects/tdp005/prototype/game_state.cpp -o CMakeFiles/sfml_test.dir/game_state.cpp.s

CMakeFiles/sfml_test.dir/level.cpp.o: CMakeFiles/sfml_test.dir/flags.make
CMakeFiles/sfml_test.dir/level.cpp.o: ../level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sfml_test.dir/level.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_test.dir/level.cpp.o -c /home/viktor/CLionProjects/tdp005/prototype/level.cpp

CMakeFiles/sfml_test.dir/level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_test.dir/level.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viktor/CLionProjects/tdp005/prototype/level.cpp > CMakeFiles/sfml_test.dir/level.cpp.i

CMakeFiles/sfml_test.dir/level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_test.dir/level.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viktor/CLionProjects/tdp005/prototype/level.cpp -o CMakeFiles/sfml_test.dir/level.cpp.s

CMakeFiles/sfml_test.dir/ingame.cpp.o: CMakeFiles/sfml_test.dir/flags.make
CMakeFiles/sfml_test.dir/ingame.cpp.o: ../ingame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sfml_test.dir/ingame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_test.dir/ingame.cpp.o -c /home/viktor/CLionProjects/tdp005/prototype/ingame.cpp

CMakeFiles/sfml_test.dir/ingame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_test.dir/ingame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viktor/CLionProjects/tdp005/prototype/ingame.cpp > CMakeFiles/sfml_test.dir/ingame.cpp.i

CMakeFiles/sfml_test.dir/ingame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_test.dir/ingame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viktor/CLionProjects/tdp005/prototype/ingame.cpp -o CMakeFiles/sfml_test.dir/ingame.cpp.s

CMakeFiles/sfml_test.dir/game_object.cpp.o: CMakeFiles/sfml_test.dir/flags.make
CMakeFiles/sfml_test.dir/game_object.cpp.o: ../game_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sfml_test.dir/game_object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_test.dir/game_object.cpp.o -c /home/viktor/CLionProjects/tdp005/prototype/game_object.cpp

CMakeFiles/sfml_test.dir/game_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_test.dir/game_object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viktor/CLionProjects/tdp005/prototype/game_object.cpp > CMakeFiles/sfml_test.dir/game_object.cpp.i

CMakeFiles/sfml_test.dir/game_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_test.dir/game_object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viktor/CLionProjects/tdp005/prototype/game_object.cpp -o CMakeFiles/sfml_test.dir/game_object.cpp.s

CMakeFiles/sfml_test.dir/terrain.cpp.o: CMakeFiles/sfml_test.dir/flags.make
CMakeFiles/sfml_test.dir/terrain.cpp.o: ../terrain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sfml_test.dir/terrain.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_test.dir/terrain.cpp.o -c /home/viktor/CLionProjects/tdp005/prototype/terrain.cpp

CMakeFiles/sfml_test.dir/terrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_test.dir/terrain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viktor/CLionProjects/tdp005/prototype/terrain.cpp > CMakeFiles/sfml_test.dir/terrain.cpp.i

CMakeFiles/sfml_test.dir/terrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_test.dir/terrain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viktor/CLionProjects/tdp005/prototype/terrain.cpp -o CMakeFiles/sfml_test.dir/terrain.cpp.s

# Object files for target sfml_test
sfml_test_OBJECTS = \
"CMakeFiles/sfml_test.dir/main.cpp.o" \
"CMakeFiles/sfml_test.dir/game.cpp.o" \
"CMakeFiles/sfml_test.dir/game_state.cpp.o" \
"CMakeFiles/sfml_test.dir/level.cpp.o" \
"CMakeFiles/sfml_test.dir/ingame.cpp.o" \
"CMakeFiles/sfml_test.dir/game_object.cpp.o" \
"CMakeFiles/sfml_test.dir/terrain.cpp.o"

# External object files for target sfml_test
sfml_test_EXTERNAL_OBJECTS =

sfml_test: CMakeFiles/sfml_test.dir/main.cpp.o
sfml_test: CMakeFiles/sfml_test.dir/game.cpp.o
sfml_test: CMakeFiles/sfml_test.dir/game_state.cpp.o
sfml_test: CMakeFiles/sfml_test.dir/level.cpp.o
sfml_test: CMakeFiles/sfml_test.dir/ingame.cpp.o
sfml_test: CMakeFiles/sfml_test.dir/game_object.cpp.o
sfml_test: CMakeFiles/sfml_test.dir/terrain.cpp.o
sfml_test: CMakeFiles/sfml_test.dir/build.make
sfml_test: CMakeFiles/sfml_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable sfml_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml_test.dir/build: sfml_test

.PHONY : CMakeFiles/sfml_test.dir/build

CMakeFiles/sfml_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml_test.dir/clean

CMakeFiles/sfml_test.dir/depend:
	cd /home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viktor/CLionProjects/tdp005/prototype /home/viktor/CLionProjects/tdp005/prototype /home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug /home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug /home/viktor/CLionProjects/tdp005/prototype/cmake-build-debug/CMakeFiles/sfml_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml_test.dir/depend

