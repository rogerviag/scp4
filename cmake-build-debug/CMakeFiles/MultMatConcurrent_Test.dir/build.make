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
CMAKE_SOURCE_DIR = /Users/rogervillarroya/CLionProjects/scp4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MultMatConcurrent_Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MultMatConcurrent_Test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MultMatConcurrent_Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MultMatConcurrent_Test.dir/flags.make

CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o: CMakeFiles/MultMatConcurrent_Test.dir/flags.make
CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o: /Users/rogervillarroya/CLionProjects/scp4/MultMatConcurrent_test.c
CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o: CMakeFiles/MultMatConcurrent_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o -MF CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o.d -o CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o -c /Users/rogervillarroya/CLionProjects/scp4/MultMatConcurrent_test.c

CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rogervillarroya/CLionProjects/scp4/MultMatConcurrent_test.c > CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.i

CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rogervillarroya/CLionProjects/scp4/MultMatConcurrent_test.c -o CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.s

CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o: CMakeFiles/MultMatConcurrent_Test.dir/flags.make
CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o: /Users/rogervillarroya/CLionProjects/scp4/Errors.c
CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o: CMakeFiles/MultMatConcurrent_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o -MF CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o.d -o CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o -c /Users/rogervillarroya/CLionProjects/scp4/Errors.c

CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rogervillarroya/CLionProjects/scp4/Errors.c > CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.i

CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rogervillarroya/CLionProjects/scp4/Errors.c -o CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.s

CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o: CMakeFiles/MultMatConcurrent_Test.dir/flags.make
CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o: /Users/rogervillarroya/CLionProjects/scp4/Matrix.c
CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o: CMakeFiles/MultMatConcurrent_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o -MF CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o.d -o CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o -c /Users/rogervillarroya/CLionProjects/scp4/Matrix.c

CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rogervillarroya/CLionProjects/scp4/Matrix.c > CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.i

CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rogervillarroya/CLionProjects/scp4/Matrix.c -o CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.s

CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o: CMakeFiles/MultMatConcurrent_Test.dir/flags.make
CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o: /Users/rogervillarroya/CLionProjects/scp4/Concurrent_Standard_MultMat.c
CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o: CMakeFiles/MultMatConcurrent_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o -MF CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o.d -o CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o -c /Users/rogervillarroya/CLionProjects/scp4/Concurrent_Standard_MultMat.c

CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rogervillarroya/CLionProjects/scp4/Concurrent_Standard_MultMat.c > CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.i

CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rogervillarroya/CLionProjects/scp4/Concurrent_Standard_MultMat.c -o CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.s

CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o: CMakeFiles/MultMatConcurrent_Test.dir/flags.make
CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o: /Users/rogervillarroya/CLionProjects/scp4/Concurrent_Strassens_MultMat.c
CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o: CMakeFiles/MultMatConcurrent_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o -MF CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o.d -o CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o -c /Users/rogervillarroya/CLionProjects/scp4/Concurrent_Strassens_MultMat.c

CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rogervillarroya/CLionProjects/scp4/Concurrent_Strassens_MultMat.c > CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.i

CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rogervillarroya/CLionProjects/scp4/Concurrent_Strassens_MultMat.c -o CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.s

# Object files for target MultMatConcurrent_Test
MultMatConcurrent_Test_OBJECTS = \
"CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o" \
"CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o" \
"CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o" \
"CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o" \
"CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o"

# External object files for target MultMatConcurrent_Test
MultMatConcurrent_Test_EXTERNAL_OBJECTS =

MultMatConcurrent_Test: CMakeFiles/MultMatConcurrent_Test.dir/MultMatConcurrent_test.c.o
MultMatConcurrent_Test: CMakeFiles/MultMatConcurrent_Test.dir/Errors.c.o
MultMatConcurrent_Test: CMakeFiles/MultMatConcurrent_Test.dir/Matrix.c.o
MultMatConcurrent_Test: CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Standard_MultMat.c.o
MultMatConcurrent_Test: CMakeFiles/MultMatConcurrent_Test.dir/Concurrent_Strassens_MultMat.c.o
MultMatConcurrent_Test: CMakeFiles/MultMatConcurrent_Test.dir/build.make
MultMatConcurrent_Test: CMakeFiles/MultMatConcurrent_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable MultMatConcurrent_Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MultMatConcurrent_Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MultMatConcurrent_Test.dir/build: MultMatConcurrent_Test
.PHONY : CMakeFiles/MultMatConcurrent_Test.dir/build

CMakeFiles/MultMatConcurrent_Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MultMatConcurrent_Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MultMatConcurrent_Test.dir/clean

CMakeFiles/MultMatConcurrent_Test.dir/depend:
	cd /Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rogervillarroya/CLionProjects/scp4 /Users/rogervillarroya/CLionProjects/scp4 /Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug /Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug /Users/rogervillarroya/CLionProjects/scp4/cmake-build-debug/CMakeFiles/MultMatConcurrent_Test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MultMatConcurrent_Test.dir/depend
