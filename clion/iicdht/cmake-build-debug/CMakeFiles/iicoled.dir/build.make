# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/jhuuhka/software/clion-2016.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jhuuhka/software/clion-2016.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jhuuhka/Arduino/git/clion/iidht

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jhuuhka/Arduino/git/clion/iidht/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/iicoled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/iicoled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/iicoled.dir/flags.make

CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o: CMakeFiles/iicoled.dir/flags.make
CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o: /home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhuuhka/Arduino/git/clion/iidht/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o"
	/home/jhuuhka/.platformio/packages/toolchain-xtensa/bin/xtensa-lx106-elf-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o -c /home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp

CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.i"
	/home/jhuuhka/.platformio/packages/toolchain-xtensa/bin/xtensa-lx106-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp > CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.i

CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.s"
	/home/jhuuhka/.platformio/packages/toolchain-xtensa/bin/xtensa-lx106-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp -o CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.s

CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o.requires:

.PHONY : CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o.requires

CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o.provides: CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o.requires
	$(MAKE) -f CMakeFiles/iicoled.dir/build.make CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o.provides.build
.PHONY : CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o.provides

CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o.provides.build: CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o


# Object files for target iicoled
iicoled_OBJECTS = \
"CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o"

# External object files for target iicoled
iicoled_EXTERNAL_OBJECTS =

iicoled: CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o
iicoled: CMakeFiles/iicoled.dir/build.make
iicoled: CMakeFiles/iicoled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jhuuhka/Arduino/git/clion/iidht/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable iicoled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iicoled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/iicoled.dir/build: iicoled

.PHONY : CMakeFiles/iicoled.dir/build

CMakeFiles/iicoled.dir/requires: CMakeFiles/iicoled.dir/home/jhuuhka/Arduino/git/clion/iicoled/src/i2cOled.cpp.o.requires

.PHONY : CMakeFiles/iicoled.dir/requires

CMakeFiles/iicoled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iicoled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iicoled.dir/clean

CMakeFiles/iicoled.dir/depend:
	cd /home/jhuuhka/Arduino/git/clion/iidht/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jhuuhka/Arduino/git/clion/iidht /home/jhuuhka/Arduino/git/clion/iidht /home/jhuuhka/Arduino/git/clion/iidht/cmake-build-debug /home/jhuuhka/Arduino/git/clion/iidht/cmake-build-debug /home/jhuuhka/Arduino/git/clion/iidht/cmake-build-debug/CMakeFiles/iicoled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/iicoled.dir/depend

