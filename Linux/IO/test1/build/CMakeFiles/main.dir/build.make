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
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/test1.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test1.c.o: ../test1.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/C-2024/Linux/IO/test1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/main.dir/test1.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main.dir/test1.c.o   -c /root/C-2024/Linux/IO/test1/test1.c

CMakeFiles/main.dir/test1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/test1.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/C-2024/Linux/IO/test1/test1.c > CMakeFiles/main.dir/test1.c.i

CMakeFiles/main.dir/test1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/test1.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/C-2024/Linux/IO/test1/test1.c -o CMakeFiles/main.dir/test1.c.s

CMakeFiles/main.dir/test1.c.o.requires:
.PHONY : CMakeFiles/main.dir/test1.c.o.requires

CMakeFiles/main.dir/test1.c.o.provides: CMakeFiles/main.dir/test1.c.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test1.c.o.provides.build
.PHONY : CMakeFiles/main.dir/test1.c.o.provides

CMakeFiles/main.dir/test1.c.o.provides.build: CMakeFiles/main.dir/test1.c.o

CMakeFiles/main.dir/lib/client.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lib/client.c.o: ../lib/client.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/C-2024/Linux/IO/test1/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/main.dir/lib/client.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main.dir/lib/client.c.o   -c /root/C-2024/Linux/IO/test1/lib/client.c

CMakeFiles/main.dir/lib/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/lib/client.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/C-2024/Linux/IO/test1/lib/client.c > CMakeFiles/main.dir/lib/client.c.i

CMakeFiles/main.dir/lib/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/lib/client.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/C-2024/Linux/IO/test1/lib/client.c -o CMakeFiles/main.dir/lib/client.c.s

CMakeFiles/main.dir/lib/client.c.o.requires:
.PHONY : CMakeFiles/main.dir/lib/client.c.o.requires

CMakeFiles/main.dir/lib/client.c.o.provides: CMakeFiles/main.dir/lib/client.c.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/lib/client.c.o.provides.build
.PHONY : CMakeFiles/main.dir/lib/client.c.o.provides

CMakeFiles/main.dir/lib/client.c.o.provides.build: CMakeFiles/main.dir/lib/client.c.o

CMakeFiles/main.dir/lib/socketutil.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lib/socketutil.c.o: ../lib/socketutil.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/C-2024/Linux/IO/test1/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/main.dir/lib/socketutil.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main.dir/lib/socketutil.c.o   -c /root/C-2024/Linux/IO/test1/lib/socketutil.c

CMakeFiles/main.dir/lib/socketutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/lib/socketutil.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/C-2024/Linux/IO/test1/lib/socketutil.c > CMakeFiles/main.dir/lib/socketutil.c.i

CMakeFiles/main.dir/lib/socketutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/lib/socketutil.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/C-2024/Linux/IO/test1/lib/socketutil.c -o CMakeFiles/main.dir/lib/socketutil.c.s

CMakeFiles/main.dir/lib/socketutil.c.o.requires:
.PHONY : CMakeFiles/main.dir/lib/socketutil.c.o.requires

CMakeFiles/main.dir/lib/socketutil.c.o.provides: CMakeFiles/main.dir/lib/socketutil.c.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/lib/socketutil.c.o.provides.build
.PHONY : CMakeFiles/main.dir/lib/socketutil.c.o.provides

CMakeFiles/main.dir/lib/socketutil.c.o.provides.build: CMakeFiles/main.dir/lib/socketutil.c.o

CMakeFiles/main.dir/lib/ipc.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lib/ipc.c.o: ../lib/ipc.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/C-2024/Linux/IO/test1/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/main.dir/lib/ipc.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main.dir/lib/ipc.c.o   -c /root/C-2024/Linux/IO/test1/lib/ipc.c

CMakeFiles/main.dir/lib/ipc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/lib/ipc.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/C-2024/Linux/IO/test1/lib/ipc.c > CMakeFiles/main.dir/lib/ipc.c.i

CMakeFiles/main.dir/lib/ipc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/lib/ipc.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/C-2024/Linux/IO/test1/lib/ipc.c -o CMakeFiles/main.dir/lib/ipc.c.s

CMakeFiles/main.dir/lib/ipc.c.o.requires:
.PHONY : CMakeFiles/main.dir/lib/ipc.c.o.requires

CMakeFiles/main.dir/lib/ipc.c.o.provides: CMakeFiles/main.dir/lib/ipc.c.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/lib/ipc.c.o.provides.build
.PHONY : CMakeFiles/main.dir/lib/ipc.c.o.provides

CMakeFiles/main.dir/lib/ipc.c.o.provides.build: CMakeFiles/main.dir/lib/ipc.c.o

CMakeFiles/main.dir/lib/common.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lib/common.c.o: ../lib/common.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/C-2024/Linux/IO/test1/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/main.dir/lib/common.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main.dir/lib/common.c.o   -c /root/C-2024/Linux/IO/test1/lib/common.c

CMakeFiles/main.dir/lib/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/lib/common.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/C-2024/Linux/IO/test1/lib/common.c > CMakeFiles/main.dir/lib/common.c.i

CMakeFiles/main.dir/lib/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/lib/common.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/C-2024/Linux/IO/test1/lib/common.c -o CMakeFiles/main.dir/lib/common.c.s

CMakeFiles/main.dir/lib/common.c.o.requires:
.PHONY : CMakeFiles/main.dir/lib/common.c.o.requires

CMakeFiles/main.dir/lib/common.c.o.provides: CMakeFiles/main.dir/lib/common.c.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/lib/common.c.o.provides.build
.PHONY : CMakeFiles/main.dir/lib/common.c.o.provides

CMakeFiles/main.dir/lib/common.c.o.provides.build: CMakeFiles/main.dir/lib/common.c.o

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/test1.c.o" \
"CMakeFiles/main.dir/lib/client.c.o" \
"CMakeFiles/main.dir/lib/socketutil.c.o" \
"CMakeFiles/main.dir/lib/ipc.c.o" \
"CMakeFiles/main.dir/lib/common.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

../main: CMakeFiles/main.dir/test1.c.o
../main: CMakeFiles/main.dir/lib/client.c.o
../main: CMakeFiles/main.dir/lib/socketutil.c.o
../main: CMakeFiles/main.dir/lib/ipc.c.o
../main: CMakeFiles/main.dir/lib/common.c.o
../main: CMakeFiles/main.dir/build.make
../main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: ../main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/test1.c.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/lib/client.c.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/lib/socketutil.c.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/lib/ipc.c.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/lib/common.c.o.requires
.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /root/C-2024/Linux/IO/test1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/C-2024/Linux/IO/test1 /root/C-2024/Linux/IO/test1 /root/C-2024/Linux/IO/test1/build /root/C-2024/Linux/IO/test1/build /root/C-2024/Linux/IO/test1/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

