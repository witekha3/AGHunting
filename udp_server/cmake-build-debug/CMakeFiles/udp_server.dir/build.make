# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/neko/clion-2019.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/neko/clion-2019.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/neko/kapik/projects/AGHunting/udp_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/udp_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udp_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp_server.dir/flags.make

CMakeFiles/udp_server.dir/main.cpp.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/udp_server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_server.dir/main.cpp.o -c /home/neko/kapik/projects/AGHunting/udp_server/main.cpp

CMakeFiles/udp_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neko/kapik/projects/AGHunting/udp_server/main.cpp > CMakeFiles/udp_server.dir/main.cpp.i

CMakeFiles/udp_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neko/kapik/projects/AGHunting/udp_server/main.cpp -o CMakeFiles/udp_server.dir/main.cpp.s

CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.o: ../src/AGHunting/GameServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.o -c /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/GameServer.cpp

CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/GameServer.cpp > CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.i

CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/GameServer.cpp -o CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.s

CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.o: ../src/AGHunting/game/PayloadHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.o -c /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/game/PayloadHandler.cpp

CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/game/PayloadHandler.cpp > CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.i

CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/game/PayloadHandler.cpp -o CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.s

CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.o: ../src/AGHunting/misc/Log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.o -c /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/misc/Log.cpp

CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/misc/Log.cpp > CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.i

CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/misc/Log.cpp -o CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.s

CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.o: ../src/AGHunting/network/SocketUDP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.o -c /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/network/SocketUDP.cpp

CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/network/SocketUDP.cpp > CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.i

CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/network/SocketUDP.cpp -o CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.s

CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.o: ../src/AGHunting/ui/Auth.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.o -c /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/ui/Auth.cpp

CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/ui/Auth.cpp > CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.i

CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/ui/Auth.cpp -o CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.s

CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.o: ../src/AGHunting/ui/ServerController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.o -c /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/ui/ServerController.cpp

CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/ui/ServerController.cpp > CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.i

CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neko/kapik/projects/AGHunting/udp_server/src/AGHunting/ui/ServerController.cpp -o CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.s

# Object files for target udp_server
udp_server_OBJECTS = \
"CMakeFiles/udp_server.dir/main.cpp.o" \
"CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.o" \
"CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.o" \
"CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.o" \
"CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.o" \
"CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.o" \
"CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.o"

# External object files for target udp_server
udp_server_EXTERNAL_OBJECTS =

udp_server: CMakeFiles/udp_server.dir/main.cpp.o
udp_server: CMakeFiles/udp_server.dir/src/AGHunting/GameServer.cpp.o
udp_server: CMakeFiles/udp_server.dir/src/AGHunting/game/PayloadHandler.cpp.o
udp_server: CMakeFiles/udp_server.dir/src/AGHunting/misc/Log.cpp.o
udp_server: CMakeFiles/udp_server.dir/src/AGHunting/network/SocketUDP.cpp.o
udp_server: CMakeFiles/udp_server.dir/src/AGHunting/ui/Auth.cpp.o
udp_server: CMakeFiles/udp_server.dir/src/AGHunting/ui/ServerController.cpp.o
udp_server: CMakeFiles/udp_server.dir/build.make
udp_server: CMakeFiles/udp_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable udp_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp_server.dir/build: udp_server

.PHONY : CMakeFiles/udp_server.dir/build

CMakeFiles/udp_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp_server.dir/clean

CMakeFiles/udp_server.dir/depend:
	cd /home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neko/kapik/projects/AGHunting/udp_server /home/neko/kapik/projects/AGHunting/udp_server /home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug /home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug /home/neko/kapik/projects/AGHunting/udp_server/cmake-build-debug/CMakeFiles/udp_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp_server.dir/depend

