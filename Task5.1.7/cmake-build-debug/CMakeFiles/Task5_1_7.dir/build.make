# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/zhenya/System/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/zhenya/System/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhenya/Projects/Task5.1.7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhenya/Projects/Task5.1.7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task5_1_7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task5_1_7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task5_1_7.dir/flags.make

CMakeFiles/Task5_1_7.dir/main.c.o: CMakeFiles/Task5_1_7.dir/flags.make
CMakeFiles/Task5_1_7.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhenya/Projects/Task5.1.7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Task5_1_7.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Task5_1_7.dir/main.c.o   -c /home/zhenya/Projects/Task5.1.7/main.c

CMakeFiles/Task5_1_7.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Task5_1_7.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zhenya/Projects/Task5.1.7/main.c > CMakeFiles/Task5_1_7.dir/main.c.i

CMakeFiles/Task5_1_7.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Task5_1_7.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zhenya/Projects/Task5.1.7/main.c -o CMakeFiles/Task5_1_7.dir/main.c.s

CMakeFiles/Task5_1_7.dir/main.c.o.requires:

.PHONY : CMakeFiles/Task5_1_7.dir/main.c.o.requires

CMakeFiles/Task5_1_7.dir/main.c.o.provides: CMakeFiles/Task5_1_7.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Task5_1_7.dir/build.make CMakeFiles/Task5_1_7.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Task5_1_7.dir/main.c.o.provides

CMakeFiles/Task5_1_7.dir/main.c.o.provides.build: CMakeFiles/Task5_1_7.dir/main.c.o


# Object files for target Task5_1_7
Task5_1_7_OBJECTS = \
"CMakeFiles/Task5_1_7.dir/main.c.o"

# External object files for target Task5_1_7
Task5_1_7_EXTERNAL_OBJECTS =

Task5_1_7: CMakeFiles/Task5_1_7.dir/main.c.o
Task5_1_7: CMakeFiles/Task5_1_7.dir/build.make
Task5_1_7: CMakeFiles/Task5_1_7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhenya/Projects/Task5.1.7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Task5_1_7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task5_1_7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task5_1_7.dir/build: Task5_1_7

.PHONY : CMakeFiles/Task5_1_7.dir/build

CMakeFiles/Task5_1_7.dir/requires: CMakeFiles/Task5_1_7.dir/main.c.o.requires

.PHONY : CMakeFiles/Task5_1_7.dir/requires

CMakeFiles/Task5_1_7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task5_1_7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task5_1_7.dir/clean

CMakeFiles/Task5_1_7.dir/depend:
	cd /home/zhenya/Projects/Task5.1.7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhenya/Projects/Task5.1.7 /home/zhenya/Projects/Task5.1.7 /home/zhenya/Projects/Task5.1.7/cmake-build-debug /home/zhenya/Projects/Task5.1.7/cmake-build-debug /home/zhenya/Projects/Task5.1.7/cmake-build-debug/CMakeFiles/Task5_1_7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task5_1_7.dir/depend

