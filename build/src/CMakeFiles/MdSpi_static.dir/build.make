# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luoyixuan/CTP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luoyixuan/CTP/build

# Include any dependencies generated for this target.
include src/CMakeFiles/MdSpi_static.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/MdSpi_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/MdSpi_static.dir/flags.make

src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o: src/CMakeFiles/MdSpi_static.dir/flags.make
src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o: ../src/MdSpi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luoyixuan/CTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o"
	cd /home/luoyixuan/CTP/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o -c /home/luoyixuan/CTP/src/MdSpi.cpp

src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MdSpi_static.dir/MdSpi.cpp.i"
	cd /home/luoyixuan/CTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luoyixuan/CTP/src/MdSpi.cpp > CMakeFiles/MdSpi_static.dir/MdSpi.cpp.i

src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MdSpi_static.dir/MdSpi.cpp.s"
	cd /home/luoyixuan/CTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luoyixuan/CTP/src/MdSpi.cpp -o CMakeFiles/MdSpi_static.dir/MdSpi.cpp.s

src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o.requires:

.PHONY : src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o.requires

src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o.provides: src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MdSpi_static.dir/build.make src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o.provides.build
.PHONY : src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o.provides

src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o.provides.build: src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o


# Object files for target MdSpi_static
MdSpi_static_OBJECTS = \
"CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o"

# External object files for target MdSpi_static
MdSpi_static_EXTERNAL_OBJECTS =

../lib/libMdSpi.a: src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o
../lib/libMdSpi.a: src/CMakeFiles/MdSpi_static.dir/build.make
../lib/libMdSpi.a: src/CMakeFiles/MdSpi_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luoyixuan/CTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libMdSpi.a"
	cd /home/luoyixuan/CTP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/MdSpi_static.dir/cmake_clean_target.cmake
	cd /home/luoyixuan/CTP/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MdSpi_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/MdSpi_static.dir/build: ../lib/libMdSpi.a

.PHONY : src/CMakeFiles/MdSpi_static.dir/build

src/CMakeFiles/MdSpi_static.dir/requires: src/CMakeFiles/MdSpi_static.dir/MdSpi.cpp.o.requires

.PHONY : src/CMakeFiles/MdSpi_static.dir/requires

src/CMakeFiles/MdSpi_static.dir/clean:
	cd /home/luoyixuan/CTP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/MdSpi_static.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/MdSpi_static.dir/clean

src/CMakeFiles/MdSpi_static.dir/depend:
	cd /home/luoyixuan/CTP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luoyixuan/CTP /home/luoyixuan/CTP/src /home/luoyixuan/CTP/build /home/luoyixuan/CTP/build/src /home/luoyixuan/CTP/build/src/CMakeFiles/MdSpi_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/MdSpi_static.dir/depend
