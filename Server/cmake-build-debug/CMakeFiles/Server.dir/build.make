# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/neko/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/neko/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/neko/projects/studia/AGHunting/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neko/projects/studia/AGHunting/Server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/src/main.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/projects/studia/AGHunting/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Server.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/src/main.c.o   -c /home/neko/projects/studia/AGHunting/Server/src/main.c

CMakeFiles/Server.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neko/projects/studia/AGHunting/Server/src/main.c > CMakeFiles/Server.dir/src/main.c.i

CMakeFiles/Server.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neko/projects/studia/AGHunting/Server/src/main.c -o CMakeFiles/Server.dir/src/main.c.s

CMakeFiles/Server.dir/libs/log/src/log.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/libs/log/src/log.c.o: ../libs/log/src/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/projects/studia/AGHunting/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Server.dir/libs/log/src/log.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/libs/log/src/log.c.o   -c /home/neko/projects/studia/AGHunting/Server/libs/log/src/log.c

CMakeFiles/Server.dir/libs/log/src/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/libs/log/src/log.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neko/projects/studia/AGHunting/Server/libs/log/src/log.c > CMakeFiles/Server.dir/libs/log/src/log.c.i

CMakeFiles/Server.dir/libs/log/src/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/libs/log/src/log.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neko/projects/studia/AGHunting/Server/libs/log/src/log.c -o CMakeFiles/Server.dir/libs/log/src/log.c.s

CMakeFiles/Server.dir/src/network/connection.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/network/connection.c.o: ../src/network/connection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/projects/studia/AGHunting/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Server.dir/src/network/connection.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/src/network/connection.c.o   -c /home/neko/projects/studia/AGHunting/Server/src/network/connection.c

CMakeFiles/Server.dir/src/network/connection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/src/network/connection.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neko/projects/studia/AGHunting/Server/src/network/connection.c > CMakeFiles/Server.dir/src/network/connection.c.i

CMakeFiles/Server.dir/src/network/connection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/src/network/connection.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neko/projects/studia/AGHunting/Server/src/network/connection.c -o CMakeFiles/Server.dir/src/network/connection.c.s

CMakeFiles/Server.dir/src/network/tcp_socket.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/network/tcp_socket.c.o: ../src/network/tcp_socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/projects/studia/AGHunting/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Server.dir/src/network/tcp_socket.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/src/network/tcp_socket.c.o   -c /home/neko/projects/studia/AGHunting/Server/src/network/tcp_socket.c

CMakeFiles/Server.dir/src/network/tcp_socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/src/network/tcp_socket.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neko/projects/studia/AGHunting/Server/src/network/tcp_socket.c > CMakeFiles/Server.dir/src/network/tcp_socket.c.i

CMakeFiles/Server.dir/src/network/tcp_socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/src/network/tcp_socket.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neko/projects/studia/AGHunting/Server/src/network/tcp_socket.c -o CMakeFiles/Server.dir/src/network/tcp_socket.c.s

CMakeFiles/Server.dir/src/server-api.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/server-api.c.o: ../src/server-api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/projects/studia/AGHunting/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Server.dir/src/server-api.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/src/server-api.c.o   -c /home/neko/projects/studia/AGHunting/Server/src/server-api.c

CMakeFiles/Server.dir/src/server-api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/src/server-api.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neko/projects/studia/AGHunting/Server/src/server-api.c > CMakeFiles/Server.dir/src/server-api.c.i

CMakeFiles/Server.dir/src/server-api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/src/server-api.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neko/projects/studia/AGHunting/Server/src/server-api.c -o CMakeFiles/Server.dir/src/server-api.c.s

CMakeFiles/Server.dir/src/ui/web_interface.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/ui/web_interface.c.o: ../src/ui/web_interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neko/projects/studia/AGHunting/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Server.dir/src/ui/web_interface.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/src/ui/web_interface.c.o   -c /home/neko/projects/studia/AGHunting/Server/src/ui/web_interface.c

CMakeFiles/Server.dir/src/ui/web_interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/src/ui/web_interface.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neko/projects/studia/AGHunting/Server/src/ui/web_interface.c > CMakeFiles/Server.dir/src/ui/web_interface.c.i

CMakeFiles/Server.dir/src/ui/web_interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/src/ui/web_interface.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neko/projects/studia/AGHunting/Server/src/ui/web_interface.c -o CMakeFiles/Server.dir/src/ui/web_interface.c.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/src/main.c.o" \
"CMakeFiles/Server.dir/libs/log/src/log.c.o" \
"CMakeFiles/Server.dir/src/network/connection.c.o" \
"CMakeFiles/Server.dir/src/network/tcp_socket.c.o" \
"CMakeFiles/Server.dir/src/server-api.c.o" \
"CMakeFiles/Server.dir/src/ui/web_interface.c.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/src/main.c.o
Server: CMakeFiles/Server.dir/libs/log/src/log.c.o
Server: CMakeFiles/Server.dir/src/network/connection.c.o
Server: CMakeFiles/Server.dir/src/network/tcp_socket.c.o
Server: CMakeFiles/Server.dir/src/server-api.c.o
Server: CMakeFiles/Server.dir/src/ui/web_interface.c.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neko/projects/studia/AGHunting/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/neko/projects/studia/AGHunting/Server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neko/projects/studia/AGHunting/Server /home/neko/projects/studia/AGHunting/Server /home/neko/projects/studia/AGHunting/Server/cmake-build-debug /home/neko/projects/studia/AGHunting/Server/cmake-build-debug /home/neko/projects/studia/AGHunting/Server/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

