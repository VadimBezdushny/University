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
CMAKE_COMMAND = /home/heimdall/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/heimdall/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/heimdall/Dev/University/Abstract Algebra/BigInt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release"

# Include any dependencies generated for this target.
include CMakeFiles/BigInt_project_run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BigInt_project_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigInt_project_run.dir/flags.make

CMakeFiles/BigInt_project_run.dir/main.cpp.o: CMakeFiles/BigInt_project_run.dir/flags.make
CMakeFiles/BigInt_project_run.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigInt_project_run.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BigInt_project_run.dir/main.cpp.o -c "/home/heimdall/Dev/University/Abstract Algebra/BigInt/main.cpp"

CMakeFiles/BigInt_project_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigInt_project_run.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/heimdall/Dev/University/Abstract Algebra/BigInt/main.cpp" > CMakeFiles/BigInt_project_run.dir/main.cpp.i

CMakeFiles/BigInt_project_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigInt_project_run.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/heimdall/Dev/University/Abstract Algebra/BigInt/main.cpp" -o CMakeFiles/BigInt_project_run.dir/main.cpp.s

CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.o: CMakeFiles/BigInt_project_run.dir/flags.make
CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.o: ../src/Console/Console.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.o -c "/home/heimdall/Dev/University/Abstract Algebra/BigInt/src/Console/Console.cc"

CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/heimdall/Dev/University/Abstract Algebra/BigInt/src/Console/Console.cc" > CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.i

CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/heimdall/Dev/University/Abstract Algebra/BigInt/src/Console/Console.cc" -o CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.s

# Object files for target BigInt_project_run
BigInt_project_run_OBJECTS = \
"CMakeFiles/BigInt_project_run.dir/main.cpp.o" \
"CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.o"

# External object files for target BigInt_project_run
BigInt_project_run_EXTERNAL_OBJECTS =

BigInt_project_run: CMakeFiles/BigInt_project_run.dir/main.cpp.o
BigInt_project_run: CMakeFiles/BigInt_project_run.dir/src/Console/Console.cc.o
BigInt_project_run: CMakeFiles/BigInt_project_run.dir/build.make
BigInt_project_run: src/BigInt/libBigInt.a
BigInt_project_run: src/Algorithms/libAlgorithms.a
BigInt_project_run: src/Console/libConsole.a
BigInt_project_run: src/Algorithms/libAlgorithms.a
BigInt_project_run: src/Console/libConsole.a
BigInt_project_run: CMakeFiles/BigInt_project_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BigInt_project_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BigInt_project_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigInt_project_run.dir/build: BigInt_project_run

.PHONY : CMakeFiles/BigInt_project_run.dir/build

CMakeFiles/BigInt_project_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BigInt_project_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BigInt_project_run.dir/clean

CMakeFiles/BigInt_project_run.dir/depend:
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/heimdall/Dev/University/Abstract Algebra/BigInt" "/home/heimdall/Dev/University/Abstract Algebra/BigInt" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles/BigInt_project_run.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BigInt_project_run.dir/depend

