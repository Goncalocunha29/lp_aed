# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/goncalocunha/CLionProjects/lp_aed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/goncalocunha/CLionProjects/lp_aed/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projeto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/projeto.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/projeto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projeto.dir/flags.make

CMakeFiles/projeto.dir/main.c.o: CMakeFiles/projeto.dir/flags.make
CMakeFiles/projeto.dir/main.c.o: /Users/goncalocunha/CLionProjects/lp_aed/main.c
CMakeFiles/projeto.dir/main.c.o: CMakeFiles/projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/goncalocunha/CLionProjects/lp_aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projeto.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/projeto.dir/main.c.o -MF CMakeFiles/projeto.dir/main.c.o.d -o CMakeFiles/projeto.dir/main.c.o -c /Users/goncalocunha/CLionProjects/lp_aed/main.c

CMakeFiles/projeto.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/projeto.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/goncalocunha/CLionProjects/lp_aed/main.c > CMakeFiles/projeto.dir/main.c.i

CMakeFiles/projeto.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/projeto.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/goncalocunha/CLionProjects/lp_aed/main.c -o CMakeFiles/projeto.dir/main.c.s

CMakeFiles/projeto.dir/projeto.c.o: CMakeFiles/projeto.dir/flags.make
CMakeFiles/projeto.dir/projeto.c.o: /Users/goncalocunha/CLionProjects/lp_aed/projeto.c
CMakeFiles/projeto.dir/projeto.c.o: CMakeFiles/projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/goncalocunha/CLionProjects/lp_aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/projeto.dir/projeto.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/projeto.dir/projeto.c.o -MF CMakeFiles/projeto.dir/projeto.c.o.d -o CMakeFiles/projeto.dir/projeto.c.o -c /Users/goncalocunha/CLionProjects/lp_aed/projeto.c

CMakeFiles/projeto.dir/projeto.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/projeto.dir/projeto.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/goncalocunha/CLionProjects/lp_aed/projeto.c > CMakeFiles/projeto.dir/projeto.c.i

CMakeFiles/projeto.dir/projeto.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/projeto.dir/projeto.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/goncalocunha/CLionProjects/lp_aed/projeto.c -o CMakeFiles/projeto.dir/projeto.c.s

# Object files for target projeto
projeto_OBJECTS = \
"CMakeFiles/projeto.dir/main.c.o" \
"CMakeFiles/projeto.dir/projeto.c.o"

# External object files for target projeto
projeto_EXTERNAL_OBJECTS =

projeto: CMakeFiles/projeto.dir/main.c.o
projeto: CMakeFiles/projeto.dir/projeto.c.o
projeto: CMakeFiles/projeto.dir/build.make
projeto: CMakeFiles/projeto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/goncalocunha/CLionProjects/lp_aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable projeto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projeto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projeto.dir/build: projeto
.PHONY : CMakeFiles/projeto.dir/build

CMakeFiles/projeto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projeto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projeto.dir/clean

CMakeFiles/projeto.dir/depend:
	cd /Users/goncalocunha/CLionProjects/lp_aed/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/goncalocunha/CLionProjects/lp_aed /Users/goncalocunha/CLionProjects/lp_aed /Users/goncalocunha/CLionProjects/lp_aed/cmake-build-debug /Users/goncalocunha/CLionProjects/lp_aed/cmake-build-debug /Users/goncalocunha/CLionProjects/lp_aed/cmake-build-debug/CMakeFiles/projeto.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/projeto.dir/depend

