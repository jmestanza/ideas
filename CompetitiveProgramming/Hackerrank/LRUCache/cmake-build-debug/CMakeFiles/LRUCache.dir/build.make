# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LRUCache.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/LRUCache.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LRUCache.dir/flags.make

CMakeFiles/LRUCache.dir/main.cpp.obj: CMakeFiles/LRUCache.dir/flags.make
CMakeFiles/LRUCache.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LRUCache.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LRUCache.dir\main.cpp.obj -c C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\main.cpp

CMakeFiles/LRUCache.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LRUCache.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\main.cpp > CMakeFiles\LRUCache.dir\main.cpp.i

CMakeFiles/LRUCache.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LRUCache.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\main.cpp -o CMakeFiles\LRUCache.dir\main.cpp.s

# Object files for target LRUCache
LRUCache_OBJECTS = \
"CMakeFiles/LRUCache.dir/main.cpp.obj"

# External object files for target LRUCache
LRUCache_EXTERNAL_OBJECTS =

LRUCache.exe: CMakeFiles/LRUCache.dir/main.cpp.obj
LRUCache.exe: CMakeFiles/LRUCache.dir/build.make
LRUCache.exe: CMakeFiles/LRUCache.dir/linklibs.rsp
LRUCache.exe: CMakeFiles/LRUCache.dir/objects1.rsp
LRUCache.exe: CMakeFiles/LRUCache.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LRUCache.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LRUCache.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LRUCache.dir/build: LRUCache.exe
.PHONY : CMakeFiles/LRUCache.dir/build

CMakeFiles/LRUCache.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LRUCache.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LRUCache.dir/clean

CMakeFiles/LRUCache.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\cmake-build-debug C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\cmake-build-debug C:\Github_Repos\ideas\CompetitiveProgramming\Hackerrank\LRUCache\cmake-build-debug\CMakeFiles\LRUCache.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LRUCache.dir/depend
