# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/Desktop/Internship_task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Desktop/Internship_task/cmake-build-debug

# Include any dependencies generated for this target.
include DB/CMakeFiles/HTTP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include DB/CMakeFiles/HTTP.dir/compiler_depend.make

# Include the progress variables for this target.
include DB/CMakeFiles/HTTP.dir/progress.make

# Include the compile flags for this target's objects.
include DB/CMakeFiles/HTTP.dir/flags.make

DB/CMakeFiles/HTTP.dir/src/HTTP.cpp.o: DB/CMakeFiles/HTTP.dir/flags.make
DB/CMakeFiles/HTTP.dir/src/HTTP.cpp.o: ../DB/src/HTTP.cpp
DB/CMakeFiles/HTTP.dir/src/HTTP.cpp.o: DB/CMakeFiles/HTTP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Desktop/Internship_task/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object DB/CMakeFiles/HTTP.dir/src/HTTP.cpp.o"
	cd /home/user/Desktop/Internship_task/cmake-build-debug/DB && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT DB/CMakeFiles/HTTP.dir/src/HTTP.cpp.o -MF CMakeFiles/HTTP.dir/src/HTTP.cpp.o.d -o CMakeFiles/HTTP.dir/src/HTTP.cpp.o -c /home/user/Desktop/Internship_task/DB/src/HTTP.cpp

DB/CMakeFiles/HTTP.dir/src/HTTP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HTTP.dir/src/HTTP.cpp.i"
	cd /home/user/Desktop/Internship_task/cmake-build-debug/DB && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Desktop/Internship_task/DB/src/HTTP.cpp > CMakeFiles/HTTP.dir/src/HTTP.cpp.i

DB/CMakeFiles/HTTP.dir/src/HTTP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HTTP.dir/src/HTTP.cpp.s"
	cd /home/user/Desktop/Internship_task/cmake-build-debug/DB && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Desktop/Internship_task/DB/src/HTTP.cpp -o CMakeFiles/HTTP.dir/src/HTTP.cpp.s

# Object files for target HTTP
HTTP_OBJECTS = \
"CMakeFiles/HTTP.dir/src/HTTP.cpp.o"

# External object files for target HTTP
HTTP_EXTERNAL_OBJECTS =

DB/HTTP: DB/CMakeFiles/HTTP.dir/src/HTTP.cpp.o
DB/HTTP: DB/CMakeFiles/HTTP.dir/build.make
DB/HTTP: DB/CMakeFiles/HTTP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Desktop/Internship_task/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HTTP"
	cd /home/user/Desktop/Internship_task/cmake-build-debug/DB && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HTTP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DB/CMakeFiles/HTTP.dir/build: DB/HTTP
.PHONY : DB/CMakeFiles/HTTP.dir/build

DB/CMakeFiles/HTTP.dir/clean:
	cd /home/user/Desktop/Internship_task/cmake-build-debug/DB && $(CMAKE_COMMAND) -P CMakeFiles/HTTP.dir/cmake_clean.cmake
.PHONY : DB/CMakeFiles/HTTP.dir/clean

DB/CMakeFiles/HTTP.dir/depend:
	cd /home/user/Desktop/Internship_task/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Desktop/Internship_task /home/user/Desktop/Internship_task/DB /home/user/Desktop/Internship_task/cmake-build-debug /home/user/Desktop/Internship_task/cmake-build-debug/DB /home/user/Desktop/Internship_task/cmake-build-debug/DB/CMakeFiles/HTTP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DB/CMakeFiles/HTTP.dir/depend
