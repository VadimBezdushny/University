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
include Tests/CMakeFiles/runBigIntTests.dir/depend.make

# Include the progress variables for this target.
include Tests/CMakeFiles/runBigIntTests.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeFiles/runBigIntTests.dir/flags.make

Tests/CMakeFiles/runBigIntTests.dir/InitTests.cpp.o: Tests/CMakeFiles/runBigIntTests.dir/flags.make
Tests/CMakeFiles/runBigIntTests.dir/InitTests.cpp.o: ../Tests/InitTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/CMakeFiles/runBigIntTests.dir/InitTests.cpp.o"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runBigIntTests.dir/InitTests.cpp.o -c "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/InitTests.cpp"

Tests/CMakeFiles/runBigIntTests.dir/InitTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runBigIntTests.dir/InitTests.cpp.i"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/InitTests.cpp" > CMakeFiles/runBigIntTests.dir/InitTests.cpp.i

Tests/CMakeFiles/runBigIntTests.dir/InitTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runBigIntTests.dir/InitTests.cpp.s"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/InitTests.cpp" -o CMakeFiles/runBigIntTests.dir/InitTests.cpp.s

Tests/CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.o: Tests/CMakeFiles/runBigIntTests.dir/flags.make
Tests/CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.o: ../Tests/ArithmeticTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Tests/CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.o"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.o -c "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/ArithmeticTests.cpp"

Tests/CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.i"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/ArithmeticTests.cpp" > CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.i

Tests/CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.s"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/ArithmeticTests.cpp" -o CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.s

Tests/CMakeFiles/runBigIntTests.dir/AlgoTests.cc.o: Tests/CMakeFiles/runBigIntTests.dir/flags.make
Tests/CMakeFiles/runBigIntTests.dir/AlgoTests.cc.o: ../Tests/AlgoTests.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Tests/CMakeFiles/runBigIntTests.dir/AlgoTests.cc.o"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runBigIntTests.dir/AlgoTests.cc.o -c "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/AlgoTests.cc"

Tests/CMakeFiles/runBigIntTests.dir/AlgoTests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runBigIntTests.dir/AlgoTests.cc.i"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/AlgoTests.cc" > CMakeFiles/runBigIntTests.dir/AlgoTests.cc.i

Tests/CMakeFiles/runBigIntTests.dir/AlgoTests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runBigIntTests.dir/AlgoTests.cc.s"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests/AlgoTests.cc" -o CMakeFiles/runBigIntTests.dir/AlgoTests.cc.s

# Object files for target runBigIntTests
runBigIntTests_OBJECTS = \
"CMakeFiles/runBigIntTests.dir/InitTests.cpp.o" \
"CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.o" \
"CMakeFiles/runBigIntTests.dir/AlgoTests.cc.o"

# External object files for target runBigIntTests
runBigIntTests_EXTERNAL_OBJECTS =

Tests/runBigIntTests: Tests/CMakeFiles/runBigIntTests.dir/InitTests.cpp.o
Tests/runBigIntTests: Tests/CMakeFiles/runBigIntTests.dir/ArithmeticTests.cpp.o
Tests/runBigIntTests: Tests/CMakeFiles/runBigIntTests.dir/AlgoTests.cc.o
Tests/runBigIntTests: Tests/CMakeFiles/runBigIntTests.dir/build.make
Tests/runBigIntTests: src/BigInt/libBigInt.a
Tests/runBigIntTests: src/Algorithms/libAlgorithms.a
Tests/runBigIntTests: lib/libgtest.a
Tests/runBigIntTests: lib/libgtest_main.a
Tests/runBigIntTests: src/Console/libConsole.a
Tests/runBigIntTests: src/Algorithms/libAlgorithms.a
Tests/runBigIntTests: src/Console/libConsole.a
Tests/runBigIntTests: lib/libgtest.a
Tests/runBigIntTests: Tests/CMakeFiles/runBigIntTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable runBigIntTests"
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runBigIntTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeFiles/runBigIntTests.dir/build: Tests/runBigIntTests

.PHONY : Tests/CMakeFiles/runBigIntTests.dir/build

Tests/CMakeFiles/runBigIntTests.dir/clean:
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" && $(CMAKE_COMMAND) -P CMakeFiles/runBigIntTests.dir/cmake_clean.cmake
.PHONY : Tests/CMakeFiles/runBigIntTests.dir/clean

Tests/CMakeFiles/runBigIntTests.dir/depend:
	cd "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/heimdall/Dev/University/Abstract Algebra/BigInt" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/Tests" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests" "/home/heimdall/Dev/University/Abstract Algebra/BigInt/cmake-build-release/Tests/CMakeFiles/runBigIntTests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : Tests/CMakeFiles/runBigIntTests.dir/depend

