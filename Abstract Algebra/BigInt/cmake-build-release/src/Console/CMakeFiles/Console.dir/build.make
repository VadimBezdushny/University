# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/heimdall/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.5107.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/heimdall/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.5107.21/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/heimdall/Dev/University/Abstract Algebra/BigInt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release"

# Include any dependencies generated for this target.
include src/Console/CMakeFiles/Console.dir/depend.make

# Include the progress variables for this target.
include src/Console/CMakeFiles/Console.dir/progress.make

# Include the compile flags for this target's objects.
include src/Console/CMakeFiles/Console.dir/flags.make

src/Console/CMakeFiles/Console.dir/Console.cc.o: src/Console/CMakeFiles/Console.dir/flags.make
src/Console/CMakeFiles/Console.dir/Console.cc.o: ../src/Console/Console.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Console/CMakeFiles/Console.dir/Console.cc.o"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/src/Console" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Console.dir/Console.cc.o -c "/home/heimdall/Dev/University/Abstract Algebra/BigInt/src/Console/Console.cc"

src/Console/CMakeFiles/Console.dir/Console.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Console.dir/Console.cc.i"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/src/Console" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/heimdall/Dev/University/Abstract Algebra/BigInt/src/Console/Console.cc" > CMakeFiles/Console.dir/Console.cc.i

src/Console/CMakeFiles/Console.dir/Console.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Console.dir/Console.cc.s"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/src/Console" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/heimdall/Dev/University/Abstract Algebra/BigInt/src/Console/Console.cc" -o CMakeFiles/Console.dir/Console.cc.s

# Object files for target Console
Console_OBJECTS = \
"CMakeFiles/Console.dir/Console.cc.o"

# External object files for target Console
Console_EXTERNAL_OBJECTS =

src/Console/libConsole.a: src/Console/CMakeFiles/Console.dir/Console.cc.o
src/Console/libConsole.a: src/Console/CMakeFiles/Console.dir/build.make
src/Console/libConsole.a: src/Console/CMakeFiles/Console.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libConsole.a"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/src/Console" && $(CMAKE_COMMAND) -P CMakeFiles/Console.dir/cmake_clean_target.cmake
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/src/Console" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Console.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Console/CMakeFiles/Console.dir/build: src/Console/libConsole.a

.PHONY : src/Console/CMakeFiles/Console.dir/build

src/Console/CMakeFiles/Console.dir/clean:
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/src/Console" && $(CMAKE_COMMAND) -P CMakeFiles/Console.dir/cmake_clean.cmake
.PHONY : src/Console/CMakeFiles/Console.dir/clean

src/Console/CMakeFiles/Console.dir/depend:
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/heimdall/Dev/University/Abstract Algebra/BigInt" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/src/Console" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/src/Console" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/src/Console/CMakeFiles/Console.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/Console/CMakeFiles/Console.dir/depend

