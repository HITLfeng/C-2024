# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/C-2024/Linux/IO/test1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/C-2024/Linux/IO/test1/build

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/lib/server.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/lib/server.c.o: ../lib/server.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/C-2024/Linux/IO/test1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/server.dir/lib/server.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/server.dir/lib/server.c.o   -c /root/C-2024/Linux/IO/test1/lib/server.c

CMakeFiles/server.dir/lib/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/lib/server.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/C-2024/Linux/IO/test1/lib/server.c > CMakeFiles/server.dir/lib/server.c.i

CMakeFiles/server.dir/lib/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/lib/server.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/C-2024/Linux/IO/test1/lib/server.c -o CMakeFiles/server.dir/lib/server.c.s

CMakeFiles/server.dir/lib/server.c.o.requires:
.PHONY : CMakeFiles/server.dir/lib/server.c.o.requires

CMakeFiles/server.dir/lib/server.c.o.provides: CMakeFiles/server.dir/lib/server.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/lib/server.c.o.provides.build
.PHONY : CMakeFiles/server.dir/lib/server.c.o.provides

CMakeFiles/server.dir/lib/server.c.o.provides.build: CMakeFiles/server.dir/lib/server.c.o

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/lib/server.c.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

../server: CMakeFiles/server.dir/lib/server.c.o
../server: CMakeFiles/server.dir/build.make
../server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: ../server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/lib/server.c.o.requires
.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /root/C-2024/Linux/IO/test1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/C-2024/Linux/IO/test1 /root/C-2024/Linux/IO/test1 /root/C-2024/Linux/IO/test1/build /root/C-2024/Linux/IO/test1/build /root/C-2024/Linux/IO/test1/build/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

