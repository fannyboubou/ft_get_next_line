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
CMAKE_COMMAND = /snap/clion/261/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/261/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fanny/getnextlinefanny

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fanny/getnextlinefanny/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GNL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GNL.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GNL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GNL.dir/flags.make

CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o: CMakeFiles/GNL.dir/flags.make
CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o: /home/fanny/getnextlinefanny/pacodir/get_next_line_utils.c
CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o: CMakeFiles/GNL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fanny/getnextlinefanny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o -MF CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o.d -o CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o -c /home/fanny/getnextlinefanny/pacodir/get_next_line_utils.c

CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fanny/getnextlinefanny/pacodir/get_next_line_utils.c > CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.i

CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fanny/getnextlinefanny/pacodir/get_next_line_utils.c -o CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.s

CMakeFiles/GNL.dir/pacodir/get_next_line.c.o: CMakeFiles/GNL.dir/flags.make
CMakeFiles/GNL.dir/pacodir/get_next_line.c.o: /home/fanny/getnextlinefanny/pacodir/get_next_line.c
CMakeFiles/GNL.dir/pacodir/get_next_line.c.o: CMakeFiles/GNL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fanny/getnextlinefanny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GNL.dir/pacodir/get_next_line.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GNL.dir/pacodir/get_next_line.c.o -MF CMakeFiles/GNL.dir/pacodir/get_next_line.c.o.d -o CMakeFiles/GNL.dir/pacodir/get_next_line.c.o -c /home/fanny/getnextlinefanny/pacodir/get_next_line.c

CMakeFiles/GNL.dir/pacodir/get_next_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GNL.dir/pacodir/get_next_line.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fanny/getnextlinefanny/pacodir/get_next_line.c > CMakeFiles/GNL.dir/pacodir/get_next_line.c.i

CMakeFiles/GNL.dir/pacodir/get_next_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GNL.dir/pacodir/get_next_line.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fanny/getnextlinefanny/pacodir/get_next_line.c -o CMakeFiles/GNL.dir/pacodir/get_next_line.c.s

# Object files for target GNL
GNL_OBJECTS = \
"CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o" \
"CMakeFiles/GNL.dir/pacodir/get_next_line.c.o"

# External object files for target GNL
GNL_EXTERNAL_OBJECTS =

GNL: CMakeFiles/GNL.dir/pacodir/get_next_line_utils.c.o
GNL: CMakeFiles/GNL.dir/pacodir/get_next_line.c.o
GNL: CMakeFiles/GNL.dir/build.make
GNL: CMakeFiles/GNL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/fanny/getnextlinefanny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable GNL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GNL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GNL.dir/build: GNL
.PHONY : CMakeFiles/GNL.dir/build

CMakeFiles/GNL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GNL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GNL.dir/clean

CMakeFiles/GNL.dir/depend:
	cd /home/fanny/getnextlinefanny/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fanny/getnextlinefanny /home/fanny/getnextlinefanny /home/fanny/getnextlinefanny/cmake-build-debug /home/fanny/getnextlinefanny/cmake-build-debug /home/fanny/getnextlinefanny/cmake-build-debug/CMakeFiles/GNL.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GNL.dir/depend

