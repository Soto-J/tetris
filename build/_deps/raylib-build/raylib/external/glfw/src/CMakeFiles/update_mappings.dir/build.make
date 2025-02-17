# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/johnsoto/Documents/cpp/projects/tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/johnsoto/Documents/cpp/projects/tetris/build

# Utility rule file for update_mappings.

# Include any custom commands dependencies for this target.
include _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/progress.make

_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/johnsoto/Documents/cpp/projects/tetris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating gamepad mappings from upstream repository"
	cd /Users/johnsoto/Documents/cpp/projects/tetris/build/_deps/raylib-src/src/external/glfw/src && /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -P /Users/johnsoto/Documents/cpp/projects/tetris/build/_deps/raylib-src/src/external/glfw/CMake/GenerateMappings.cmake mappings.h.in mappings.h

update_mappings: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings
update_mappings: _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/build.make
.PHONY : update_mappings

# Rule to build all files generated by this target.
_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/build: update_mappings
.PHONY : _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/build

_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/clean:
	cd /Users/johnsoto/Documents/cpp/projects/tetris/build/_deps/raylib-build/raylib/external/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/update_mappings.dir/cmake_clean.cmake
.PHONY : _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/clean

_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/depend:
	cd /Users/johnsoto/Documents/cpp/projects/tetris/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/johnsoto/Documents/cpp/projects/tetris /Users/johnsoto/Documents/cpp/projects/tetris/build/_deps/raylib-src/src/external/glfw/src /Users/johnsoto/Documents/cpp/projects/tetris/build /Users/johnsoto/Documents/cpp/projects/tetris/build/_deps/raylib-build/raylib/external/glfw/src /Users/johnsoto/Documents/cpp/projects/tetris/build/_deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/raylib-build/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/depend

