# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\ideas\DynamicProgramming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\ideas\DynamicProgramming\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DynamicProgramming.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DynamicProgramming.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DynamicProgramming.dir/flags.make

CMakeFiles/DynamicProgramming.dir/main.cpp.obj: CMakeFiles/DynamicProgramming.dir/flags.make
CMakeFiles/DynamicProgramming.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\ideas\DynamicProgramming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DynamicProgramming.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DynamicProgramming.dir\main.cpp.obj -c C:\ideas\DynamicProgramming\main.cpp

CMakeFiles/DynamicProgramming.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DynamicProgramming.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\ideas\DynamicProgramming\main.cpp > CMakeFiles\DynamicProgramming.dir\main.cpp.i

CMakeFiles/DynamicProgramming.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DynamicProgramming.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\ideas\DynamicProgramming\main.cpp -o CMakeFiles\DynamicProgramming.dir\main.cpp.s

# Object files for target DynamicProgramming
DynamicProgramming_OBJECTS = \
"CMakeFiles/DynamicProgramming.dir/main.cpp.obj"

# External object files for target DynamicProgramming
DynamicProgramming_EXTERNAL_OBJECTS =

DynamicProgramming.exe: CMakeFiles/DynamicProgramming.dir/main.cpp.obj
DynamicProgramming.exe: CMakeFiles/DynamicProgramming.dir/build.make
DynamicProgramming.exe: CMakeFiles/DynamicProgramming.dir/linklibs.rsp
DynamicProgramming.exe: CMakeFiles/DynamicProgramming.dir/objects1.rsp
DynamicProgramming.exe: CMakeFiles/DynamicProgramming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\ideas\DynamicProgramming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DynamicProgramming.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DynamicProgramming.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DynamicProgramming.dir/build: DynamicProgramming.exe

.PHONY : CMakeFiles/DynamicProgramming.dir/build

CMakeFiles/DynamicProgramming.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DynamicProgramming.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DynamicProgramming.dir/clean

CMakeFiles/DynamicProgramming.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\ideas\DynamicProgramming C:\ideas\DynamicProgramming C:\ideas\DynamicProgramming\cmake-build-debug C:\ideas\DynamicProgramming\cmake-build-debug C:\ideas\DynamicProgramming\cmake-build-debug\CMakeFiles\DynamicProgramming.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DynamicProgramming.dir/depend

