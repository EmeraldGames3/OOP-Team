# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /home/bogdan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/231.9011.31/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/bogdan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/231.9011.31/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bogdan/Programming/University/OOP-Team/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bogdan/Programming/University/OOP-Team/Project/cmake-build-debug

# Utility rule file for Project_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/Project_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_autogen.dir/progress.make

CMakeFiles/Project_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bogdan/Programming/University/OOP-Team/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target Project"
	/home/bogdan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/231.9011.31/bin/cmake/linux/x64/bin/cmake -E cmake_autogen /home/bogdan/Programming/University/OOP-Team/Project/cmake-build-debug/CMakeFiles/Project_autogen.dir/AutogenInfo.json Debug

Project_autogen: CMakeFiles/Project_autogen
Project_autogen: CMakeFiles/Project_autogen.dir/build.make
.PHONY : Project_autogen

# Rule to build all files generated by this target.
CMakeFiles/Project_autogen.dir/build: Project_autogen
.PHONY : CMakeFiles/Project_autogen.dir/build

CMakeFiles/Project_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_autogen.dir/clean

CMakeFiles/Project_autogen.dir/depend:
	cd /home/bogdan/Programming/University/OOP-Team/Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bogdan/Programming/University/OOP-Team/Project /home/bogdan/Programming/University/OOP-Team/Project /home/bogdan/Programming/University/OOP-Team/Project/cmake-build-debug /home/bogdan/Programming/University/OOP-Team/Project/cmake-build-debug /home/bogdan/Programming/University/OOP-Team/Project/cmake-build-debug/CMakeFiles/Project_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project_autogen.dir/depend

