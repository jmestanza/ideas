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
CMAKE_SOURCE_DIR = C:\Users\joa-m\tst\incisoC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\joa-m\tst\incisoC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/incisoC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/incisoC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/incisoC.dir/flags.make

CMakeFiles/incisoC.dir/main.cpp.obj: CMakeFiles/incisoC.dir/flags.make
CMakeFiles/incisoC.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\joa-m\tst\incisoC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/incisoC.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\incisoC.dir\main.cpp.obj -c C:\Users\joa-m\tst\incisoC\main.cpp

CMakeFiles/incisoC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/incisoC.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\joa-m\tst\incisoC\main.cpp > CMakeFiles\incisoC.dir\main.cpp.i

CMakeFiles/incisoC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/incisoC.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\joa-m\tst\incisoC\main.cpp -o CMakeFiles\incisoC.dir\main.cpp.s

CMakeFiles/incisoC.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/incisoC.dir/main.cpp.obj.requires

CMakeFiles/incisoC.dir/main.cpp.obj.provides: CMakeFiles/incisoC.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\incisoC.dir\build.make CMakeFiles/incisoC.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/incisoC.dir/main.cpp.obj.provides

CMakeFiles/incisoC.dir/main.cpp.obj.provides.build: CMakeFiles/incisoC.dir/main.cpp.obj


# Object files for target incisoC
incisoC_OBJECTS = \
"CMakeFiles/incisoC.dir/main.cpp.obj"

# External object files for target incisoC
incisoC_EXTERNAL_OBJECTS =

incisoC.exe: CMakeFiles/incisoC.dir/main.cpp.obj
incisoC.exe: CMakeFiles/incisoC.dir/build.make
incisoC.exe: CMakeFiles/incisoC.dir/linklibs.rsp
incisoC.exe: CMakeFiles/incisoC.dir/objects1.rsp
incisoC.exe: CMakeFiles/incisoC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\joa-m\tst\incisoC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable incisoC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\incisoC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/incisoC.dir/build: incisoC.exe

.PHONY : CMakeFiles/incisoC.dir/build

CMakeFiles/incisoC.dir/requires: CMakeFiles/incisoC.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/incisoC.dir/requires

CMakeFiles/incisoC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\incisoC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/incisoC.dir/clean

CMakeFiles/incisoC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\joa-m\tst\incisoC C:\Users\joa-m\tst\incisoC C:\Users\joa-m\tst\incisoC\cmake-build-debug C:\Users\joa-m\tst\incisoC\cmake-build-debug C:\Users\joa-m\tst\incisoC\cmake-build-debug\CMakeFiles\incisoC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/incisoC.dir/depend

