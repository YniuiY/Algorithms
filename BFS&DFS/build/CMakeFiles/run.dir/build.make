# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = D:/cmake/bin/cmake.exe

# The command to remove a file.
RM = D:/cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/codeTest/BFS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/codeTest/BFS/build

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/src/Graph.cpp.obj: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/Graph.cpp.obj: CMakeFiles/run.dir/includes_CXX.rsp
CMakeFiles/run.dir/src/Graph.cpp.obj: ../src/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/codeTest/BFS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run.dir/src/Graph.cpp.obj"
	"C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/c++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/Graph.cpp.obj -c D:/codeTest/BFS/src/Graph.cpp

CMakeFiles/run.dir/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/Graph.cpp.i"
	"C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/c++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/codeTest/BFS/src/Graph.cpp > CMakeFiles/run.dir/src/Graph.cpp.i

CMakeFiles/run.dir/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/Graph.cpp.s"
	"C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/c++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/codeTest/BFS/src/Graph.cpp -o CMakeFiles/run.dir/src/Graph.cpp.s

CMakeFiles/run.dir/src/main.cpp.obj: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/main.cpp.obj: CMakeFiles/run.dir/includes_CXX.rsp
CMakeFiles/run.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/codeTest/BFS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run.dir/src/main.cpp.obj"
	"C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/c++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/main.cpp.obj -c D:/codeTest/BFS/src/main.cpp

CMakeFiles/run.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/main.cpp.i"
	"C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/c++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/codeTest/BFS/src/main.cpp > CMakeFiles/run.dir/src/main.cpp.i

CMakeFiles/run.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/main.cpp.s"
	"C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/c++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/codeTest/BFS/src/main.cpp -o CMakeFiles/run.dir/src/main.cpp.s

# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/src/Graph.cpp.obj" \
"CMakeFiles/run.dir/src/main.cpp.obj"

# External object files for target run
run_EXTERNAL_OBJECTS =

run.exe: CMakeFiles/run.dir/src/Graph.cpp.obj
run.exe: CMakeFiles/run.dir/src/main.cpp.obj
run.exe: CMakeFiles/run.dir/build.make
run.exe: CMakeFiles/run.dir/linklibs.rsp
run.exe: CMakeFiles/run.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/codeTest/BFS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run.exe"
	D:/cmake/bin/cmake.exe -E rm -f CMakeFiles/run.dir/objects.a
	"C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/ar.exe" cr CMakeFiles/run.dir/objects.a @CMakeFiles/run.dir/objects1.rsp
	"C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/c++.exe" -Wl,--whole-archive CMakeFiles/run.dir/objects.a -Wl,--no-whole-archive -o run.exe -Wl,--out-implib,librun.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/run.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run.exe

.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/codeTest/BFS D:/codeTest/BFS D:/codeTest/BFS/build D:/codeTest/BFS/build D:/codeTest/BFS/build/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend

