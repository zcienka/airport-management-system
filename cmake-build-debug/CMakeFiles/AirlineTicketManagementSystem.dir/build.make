# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AirlineTicketManagementSystem.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/AirlineTicketManagementSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AirlineTicketManagementSystem.dir/flags.make

CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.obj: CMakeFiles/AirlineTicketManagementSystem.dir/flags.make
CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AirlineTicketManagementSystem.dir\main.cpp.obj -c C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\main.cpp

CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\main.cpp > CMakeFiles\AirlineTicketManagementSystem.dir\main.cpp.i

CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\main.cpp -o CMakeFiles\AirlineTicketManagementSystem.dir\main.cpp.s

CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.obj: CMakeFiles/AirlineTicketManagementSystem.dir/flags.make
CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.obj: ../Tickets/BusinessClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AirlineTicketManagementSystem.dir\Tickets\BusinessClass.cpp.obj -c C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Tickets\BusinessClass.cpp

CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Tickets\BusinessClass.cpp > CMakeFiles\AirlineTicketManagementSystem.dir\Tickets\BusinessClass.cpp.i

CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Tickets\BusinessClass.cpp -o CMakeFiles\AirlineTicketManagementSystem.dir\Tickets\BusinessClass.cpp.s

CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.obj: CMakeFiles/AirlineTicketManagementSystem.dir/flags.make
CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.obj: ../Tickets/RegularClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AirlineTicketManagementSystem.dir\Tickets\RegularClass.cpp.obj -c C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Tickets\RegularClass.cpp

CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Tickets\RegularClass.cpp > CMakeFiles\AirlineTicketManagementSystem.dir\Tickets\RegularClass.cpp.i

CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Tickets\RegularClass.cpp -o CMakeFiles\AirlineTicketManagementSystem.dir\Tickets\RegularClass.cpp.s

CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.obj: CMakeFiles/AirlineTicketManagementSystem.dir/flags.make
CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.obj: ../Person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AirlineTicketManagementSystem.dir\Person.cpp.obj -c C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Person.cpp

CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Person.cpp > CMakeFiles\AirlineTicketManagementSystem.dir\Person.cpp.i

CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\Person.cpp -o CMakeFiles\AirlineTicketManagementSystem.dir\Person.cpp.s

# Object files for target AirlineTicketManagementSystem
AirlineTicketManagementSystem_OBJECTS = \
"CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.obj" \
"CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.obj" \
"CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.obj" \
"CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.obj"

# External object files for target AirlineTicketManagementSystem
AirlineTicketManagementSystem_EXTERNAL_OBJECTS =

AirlineTicketManagementSystem.exe: CMakeFiles/AirlineTicketManagementSystem.dir/main.cpp.obj
AirlineTicketManagementSystem.exe: CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/BusinessClass.cpp.obj
AirlineTicketManagementSystem.exe: CMakeFiles/AirlineTicketManagementSystem.dir/Tickets/RegularClass.cpp.obj
AirlineTicketManagementSystem.exe: CMakeFiles/AirlineTicketManagementSystem.dir/Person.cpp.obj
AirlineTicketManagementSystem.exe: CMakeFiles/AirlineTicketManagementSystem.dir/build.make
AirlineTicketManagementSystem.exe: CMakeFiles/AirlineTicketManagementSystem.dir/linklibs.rsp
AirlineTicketManagementSystem.exe: CMakeFiles/AirlineTicketManagementSystem.dir/objects1.rsp
AirlineTicketManagementSystem.exe: CMakeFiles/AirlineTicketManagementSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable AirlineTicketManagementSystem.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AirlineTicketManagementSystem.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AirlineTicketManagementSystem.dir/build: AirlineTicketManagementSystem.exe
.PHONY : CMakeFiles/AirlineTicketManagementSystem.dir/build

CMakeFiles/AirlineTicketManagementSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AirlineTicketManagementSystem.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AirlineTicketManagementSystem.dir/clean

CMakeFiles/AirlineTicketManagementSystem.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug C:\Users\zuzan\Desktop\repos\AirlineTicketManagementSystem\cmake-build-debug\CMakeFiles\AirlineTicketManagementSystem.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AirlineTicketManagementSystem.dir/depend

