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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/silverbullet/SAMUDRA/catkin_ws/src/arduino/firmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/silverbullet/SAMUDRA/catkin_ws/build/arduino/firmware

# Utility rule file for control-size.

# Include the progress variables for this target.
include CMakeFiles/control-size.dir/progress.make

CMakeFiles/control-size: /home/silverbullet/SAMUDRA/catkin_ws/devel/share/arduino/control.elf
	$(CMAKE_COMMAND) -E cmake_progress_report /home/silverbullet/SAMUDRA/catkin_ws/build/arduino/firmware/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Calculating control image size"
	/usr/bin/cmake -DFIRMWARE_IMAGE=/home/silverbullet/SAMUDRA/catkin_ws/devel/share/arduino/control.elf -DMCU=atmega1280 -DEEPROM_IMAGE=/home/silverbullet/SAMUDRA/catkin_ws/devel/share/arduino/control.eep -P /home/silverbullet/SAMUDRA/catkin_ws/build/arduino/firmware/CMakeFiles/FirmwareSize.cmake

control-size: CMakeFiles/control-size
control-size: CMakeFiles/control-size.dir/build.make
.PHONY : control-size

# Rule to build all files generated by this target.
CMakeFiles/control-size.dir/build: control-size
.PHONY : CMakeFiles/control-size.dir/build

CMakeFiles/control-size.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/control-size.dir/cmake_clean.cmake
.PHONY : CMakeFiles/control-size.dir/clean

CMakeFiles/control-size.dir/depend:
	cd /home/silverbullet/SAMUDRA/catkin_ws/build/arduino/firmware && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/silverbullet/SAMUDRA/catkin_ws/src/arduino/firmware /home/silverbullet/SAMUDRA/catkin_ws/src/arduino/firmware /home/silverbullet/SAMUDRA/catkin_ws/build/arduino/firmware /home/silverbullet/SAMUDRA/catkin_ws/build/arduino/firmware /home/silverbullet/SAMUDRA/catkin_ws/build/arduino/firmware/CMakeFiles/control-size.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/control-size.dir/depend

