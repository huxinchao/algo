# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/Administrator/Desktop/cppsol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/Administrator/Desktop/cppsol/build

# Include any dependencies generated for this target.
include CMakeFiles/tmp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tmp.dir/flags.make

CMakeFiles/tmp.dir/tmp.cpp.obj: CMakeFiles/tmp.dir/flags.make
CMakeFiles/tmp.dir/tmp.cpp.obj: ../tmp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/Administrator/Desktop/cppsol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tmp.dir/tmp.cpp.obj"
	c:/mingw/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tmp.dir/tmp.cpp.obj -c C:/Users/Administrator/Desktop/cppsol/tmp.cpp

CMakeFiles/tmp.dir/tmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tmp.dir/tmp.cpp.i"
	c:/mingw/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/Administrator/Desktop/cppsol/tmp.cpp > CMakeFiles/tmp.dir/tmp.cpp.i

CMakeFiles/tmp.dir/tmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tmp.dir/tmp.cpp.s"
	c:/mingw/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/Administrator/Desktop/cppsol/tmp.cpp -o CMakeFiles/tmp.dir/tmp.cpp.s

# Object files for target tmp
tmp_OBJECTS = \
"CMakeFiles/tmp.dir/tmp.cpp.obj"

# External object files for target tmp
tmp_EXTERNAL_OBJECTS =

tmp.exe: CMakeFiles/tmp.dir/tmp.cpp.obj
tmp.exe: CMakeFiles/tmp.dir/build.make
tmp.exe: CMakeFiles/tmp.dir/linklibs.rsp
tmp.exe: CMakeFiles/tmp.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/Administrator/Desktop/cppsol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tmp.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E remove -f CMakeFiles/tmp.dir/objects.a
	C:/MinGW/bin/ar.exe cr CMakeFiles/tmp.dir/objects.a @CMakeFiles/tmp.dir/objects1.rsp
	c:/mingw/bin/g++.exe -g   -Wl,--whole-archive CMakeFiles/tmp.dir/objects.a -Wl,--no-whole-archive  -o tmp.exe -Wl,--out-implib,libtmp.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/tmp.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/tmp.dir/build: tmp.exe

.PHONY : CMakeFiles/tmp.dir/build

CMakeFiles/tmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tmp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tmp.dir/clean

CMakeFiles/tmp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/Administrator/Desktop/cppsol C:/Users/Administrator/Desktop/cppsol C:/Users/Administrator/Desktop/cppsol/build C:/Users/Administrator/Desktop/cppsol/build C:/Users/Administrator/Desktop/cppsol/build/CMakeFiles/tmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tmp.dir/depend

