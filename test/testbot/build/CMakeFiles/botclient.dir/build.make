# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rk3588/chat_project/test/testbot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rk3588/chat_project/test/testbot/build

# Include any dependencies generated for this target.
include CMakeFiles/botclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/botclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/botclient.dir/flags.make

CMakeFiles/botclient.dir/botclient.cpp.o: CMakeFiles/botclient.dir/flags.make
CMakeFiles/botclient.dir/botclient.cpp.o: ../botclient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rk3588/chat_project/test/testbot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/botclient.dir/botclient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/botclient.dir/botclient.cpp.o -c /home/rk3588/chat_project/test/testbot/botclient.cpp

CMakeFiles/botclient.dir/botclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/botclient.dir/botclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rk3588/chat_project/test/testbot/botclient.cpp > CMakeFiles/botclient.dir/botclient.cpp.i

CMakeFiles/botclient.dir/botclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/botclient.dir/botclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rk3588/chat_project/test/testbot/botclient.cpp -o CMakeFiles/botclient.dir/botclient.cpp.s

# Object files for target botclient
botclient_OBJECTS = \
"CMakeFiles/botclient.dir/botclient.cpp.o"

# External object files for target botclient
botclient_EXTERNAL_OBJECTS =

botclient: CMakeFiles/botclient.dir/botclient.cpp.o
botclient: CMakeFiles/botclient.dir/build.make
botclient: CMakeFiles/botclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rk3588/chat_project/test/testbot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable botclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/botclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/botclient.dir/build: botclient

.PHONY : CMakeFiles/botclient.dir/build

CMakeFiles/botclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/botclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/botclient.dir/clean

CMakeFiles/botclient.dir/depend:
	cd /home/rk3588/chat_project/test/testbot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rk3588/chat_project/test/testbot /home/rk3588/chat_project/test/testbot /home/rk3588/chat_project/test/testbot/build /home/rk3588/chat_project/test/testbot/build /home/rk3588/chat_project/test/testbot/build/CMakeFiles/botclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/botclient.dir/depend
