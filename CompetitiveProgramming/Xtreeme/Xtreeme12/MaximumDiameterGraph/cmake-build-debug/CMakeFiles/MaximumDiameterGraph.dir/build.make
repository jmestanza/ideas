# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.6\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.6\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\joa-m\CLionProjects\MaximumDiameterGraph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MaximumDiameterGraph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MaximumDiameterGraph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MaximumDiameterGraph.dir/flags.make

CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj: CMakeFiles/MaximumDiameterGraph.dir/flags.make
CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MaximumDiameterGraph.dir\main.cpp.obj -c C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\main.cpp

CMakeFiles/MaximumDiameterGraph.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MaximumDiameterGraph.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\main.cpp > CMakeFiles\MaximumDiameterGraph.dir\main.cpp.i

CMakeFiles/MaximumDiameterGraph.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MaximumDiameterGraph.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\main.cpp -o CMakeFiles\MaximumDiameterGraph.dir\main.cpp.s

CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj.requires

CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj.provides: CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\MaximumDiameterGraph.dir\build.make CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj.provides

CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj.provides.build: CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj


# Object files for target MaximumDiameterGraph
MaximumDiameterGraph_OBJECTS = \
"CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj"

# External object files for target MaximumDiameterGraph
MaximumDiameterGraph_EXTERNAL_OBJECTS =

MaximumDiameterGraph.exe: CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj
MaximumDiameterGraph.exe: CMakeFiles/MaximumDiameterGraph.dir/build.make
MaximumDiameterGraph.exe: CMakeFiles/MaximumDiameterGraph.dir/linklibs.rsp
MaximumDiameterGraph.exe: CMakeFiles/MaximumDiameterGraph.dir/objects1.rsp
MaximumDiameterGraph.exe: CMakeFiles/MaximumDiameterGraph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MaximumDiameterGraph.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MaximumDiameterGraph.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MaximumDiameterGraph.dir/build: MaximumDiameterGraph.exe

.PHONY : CMakeFiles/MaximumDiameterGraph.dir/build

CMakeFiles/MaximumDiameterGraph.dir/requires: CMakeFiles/MaximumDiameterGraph.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/MaximumDiameterGraph.dir/requires

CMakeFiles/MaximumDiameterGraph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MaximumDiameterGraph.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MaximumDiameterGraph.dir/clean

CMakeFiles/MaximumDiameterGraph.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\joa-m\CLionProjects\MaximumDiameterGraph C:\Users\joa-m\CLionProjects\MaximumDiameterGraph C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\cmake-build-debug C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\cmake-build-debug C:\Users\joa-m\CLionProjects\MaximumDiameterGraph\cmake-build-debug\CMakeFiles\MaximumDiameterGraph.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MaximumDiameterGraph.dir/depend

