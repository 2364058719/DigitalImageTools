# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code\C++Project\digital_image

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\C++Project\digital_image\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/digital_image.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/digital_image.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/digital_image.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/digital_image.dir/flags.make

CMakeFiles/digital_image.dir/main.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/main.cpp.obj: D:/Code/C++Project/digital_image/main.cpp
CMakeFiles/digital_image.dir/main.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/digital_image.dir/main.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/main.cpp.obj -MF CMakeFiles\digital_image.dir\main.cpp.obj.d -o CMakeFiles\digital_image.dir\main.cpp.obj -c D:\Code\C++Project\digital_image\main.cpp

CMakeFiles/digital_image.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/main.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\main.cpp > CMakeFiles\digital_image.dir\main.cpp.i

CMakeFiles/digital_image.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/main.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\main.cpp -o CMakeFiles\digital_image.dir\main.cpp.s

CMakeFiles/digital_image.dir/bmp.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/bmp.cpp.obj: D:/Code/C++Project/digital_image/bmp.cpp
CMakeFiles/digital_image.dir/bmp.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/digital_image.dir/bmp.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/bmp.cpp.obj -MF CMakeFiles\digital_image.dir\bmp.cpp.obj.d -o CMakeFiles\digital_image.dir\bmp.cpp.obj -c D:\Code\C++Project\digital_image\bmp.cpp

CMakeFiles/digital_image.dir/bmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/bmp.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\bmp.cpp > CMakeFiles\digital_image.dir\bmp.cpp.i

CMakeFiles/digital_image.dir/bmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/bmp.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\bmp.cpp -o CMakeFiles\digital_image.dir\bmp.cpp.s

CMakeFiles/digital_image.dir/histogram.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/histogram.cpp.obj: D:/Code/C++Project/digital_image/histogram.cpp
CMakeFiles/digital_image.dir/histogram.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/digital_image.dir/histogram.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/histogram.cpp.obj -MF CMakeFiles\digital_image.dir\histogram.cpp.obj.d -o CMakeFiles\digital_image.dir\histogram.cpp.obj -c D:\Code\C++Project\digital_image\histogram.cpp

CMakeFiles/digital_image.dir/histogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/histogram.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\histogram.cpp > CMakeFiles\digital_image.dir\histogram.cpp.i

CMakeFiles/digital_image.dir/histogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/histogram.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\histogram.cpp -o CMakeFiles\digital_image.dir\histogram.cpp.s

CMakeFiles/digital_image.dir/filter.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/filter.cpp.obj: D:/Code/C++Project/digital_image/filter.cpp
CMakeFiles/digital_image.dir/filter.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/digital_image.dir/filter.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/filter.cpp.obj -MF CMakeFiles\digital_image.dir\filter.cpp.obj.d -o CMakeFiles\digital_image.dir\filter.cpp.obj -c D:\Code\C++Project\digital_image\filter.cpp

CMakeFiles/digital_image.dir/filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/filter.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\filter.cpp > CMakeFiles\digital_image.dir\filter.cpp.i

CMakeFiles/digital_image.dir/filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/filter.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\filter.cpp -o CMakeFiles\digital_image.dir\filter.cpp.s

CMakeFiles/digital_image.dir/transform.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/transform.cpp.obj: D:/Code/C++Project/digital_image/transform.cpp
CMakeFiles/digital_image.dir/transform.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/digital_image.dir/transform.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/transform.cpp.obj -MF CMakeFiles\digital_image.dir\transform.cpp.obj.d -o CMakeFiles\digital_image.dir\transform.cpp.obj -c D:\Code\C++Project\digital_image\transform.cpp

CMakeFiles/digital_image.dir/transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/transform.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\transform.cpp > CMakeFiles\digital_image.dir\transform.cpp.i

CMakeFiles/digital_image.dir/transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/transform.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\transform.cpp -o CMakeFiles\digital_image.dir\transform.cpp.s

CMakeFiles/digital_image.dir/threshold.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/threshold.cpp.obj: D:/Code/C++Project/digital_image/threshold.cpp
CMakeFiles/digital_image.dir/threshold.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/digital_image.dir/threshold.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/threshold.cpp.obj -MF CMakeFiles\digital_image.dir\threshold.cpp.obj.d -o CMakeFiles\digital_image.dir\threshold.cpp.obj -c D:\Code\C++Project\digital_image\threshold.cpp

CMakeFiles/digital_image.dir/threshold.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/threshold.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\threshold.cpp > CMakeFiles\digital_image.dir\threshold.cpp.i

CMakeFiles/digital_image.dir/threshold.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/threshold.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\threshold.cpp -o CMakeFiles\digital_image.dir\threshold.cpp.s

CMakeFiles/digital_image.dir/region.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/region.cpp.obj: D:/Code/C++Project/digital_image/region.cpp
CMakeFiles/digital_image.dir/region.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/digital_image.dir/region.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/region.cpp.obj -MF CMakeFiles\digital_image.dir\region.cpp.obj.d -o CMakeFiles\digital_image.dir\region.cpp.obj -c D:\Code\C++Project\digital_image\region.cpp

CMakeFiles/digital_image.dir/region.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/region.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\region.cpp > CMakeFiles\digital_image.dir\region.cpp.i

CMakeFiles/digital_image.dir/region.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/region.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\region.cpp -o CMakeFiles\digital_image.dir\region.cpp.s

CMakeFiles/digital_image.dir/edgeDetection.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/edgeDetection.cpp.obj: D:/Code/C++Project/digital_image/edgeDetection.cpp
CMakeFiles/digital_image.dir/edgeDetection.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/digital_image.dir/edgeDetection.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/edgeDetection.cpp.obj -MF CMakeFiles\digital_image.dir\edgeDetection.cpp.obj.d -o CMakeFiles\digital_image.dir\edgeDetection.cpp.obj -c D:\Code\C++Project\digital_image\edgeDetection.cpp

CMakeFiles/digital_image.dir/edgeDetection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/edgeDetection.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\edgeDetection.cpp > CMakeFiles\digital_image.dir\edgeDetection.cpp.i

CMakeFiles/digital_image.dir/edgeDetection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/edgeDetection.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\edgeDetection.cpp -o CMakeFiles\digital_image.dir\edgeDetection.cpp.s

CMakeFiles/digital_image.dir/houghTransform.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/houghTransform.cpp.obj: D:/Code/C++Project/digital_image/houghTransform.cpp
CMakeFiles/digital_image.dir/houghTransform.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/digital_image.dir/houghTransform.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/houghTransform.cpp.obj -MF CMakeFiles\digital_image.dir\houghTransform.cpp.obj.d -o CMakeFiles\digital_image.dir\houghTransform.cpp.obj -c D:\Code\C++Project\digital_image\houghTransform.cpp

CMakeFiles/digital_image.dir/houghTransform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/houghTransform.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\houghTransform.cpp > CMakeFiles\digital_image.dir\houghTransform.cpp.i

CMakeFiles/digital_image.dir/houghTransform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/houghTransform.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\houghTransform.cpp -o CMakeFiles\digital_image.dir\houghTransform.cpp.s

CMakeFiles/digital_image.dir/regionLabel.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/regionLabel.cpp.obj: D:/Code/C++Project/digital_image/regionLabel.cpp
CMakeFiles/digital_image.dir/regionLabel.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/digital_image.dir/regionLabel.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/regionLabel.cpp.obj -MF CMakeFiles\digital_image.dir\regionLabel.cpp.obj.d -o CMakeFiles\digital_image.dir\regionLabel.cpp.obj -c D:\Code\C++Project\digital_image\regionLabel.cpp

CMakeFiles/digital_image.dir/regionLabel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/regionLabel.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\regionLabel.cpp > CMakeFiles\digital_image.dir\regionLabel.cpp.i

CMakeFiles/digital_image.dir/regionLabel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/regionLabel.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\regionLabel.cpp -o CMakeFiles\digital_image.dir\regionLabel.cpp.s

CMakeFiles/digital_image.dir/extractContour.cpp.obj: CMakeFiles/digital_image.dir/flags.make
CMakeFiles/digital_image.dir/extractContour.cpp.obj: D:/Code/C++Project/digital_image/extractContour.cpp
CMakeFiles/digital_image.dir/extractContour.cpp.obj: CMakeFiles/digital_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/digital_image.dir/extractContour.cpp.obj"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/digital_image.dir/extractContour.cpp.obj -MF CMakeFiles\digital_image.dir\extractContour.cpp.obj.d -o CMakeFiles\digital_image.dir\extractContour.cpp.obj -c D:\Code\C++Project\digital_image\extractContour.cpp

CMakeFiles/digital_image.dir/extractContour.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/digital_image.dir/extractContour.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++Project\digital_image\extractContour.cpp > CMakeFiles\digital_image.dir\extractContour.cpp.i

CMakeFiles/digital_image.dir/extractContour.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/digital_image.dir/extractContour.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++Project\digital_image\extractContour.cpp -o CMakeFiles\digital_image.dir\extractContour.cpp.s

# Object files for target digital_image
digital_image_OBJECTS = \
"CMakeFiles/digital_image.dir/main.cpp.obj" \
"CMakeFiles/digital_image.dir/bmp.cpp.obj" \
"CMakeFiles/digital_image.dir/histogram.cpp.obj" \
"CMakeFiles/digital_image.dir/filter.cpp.obj" \
"CMakeFiles/digital_image.dir/transform.cpp.obj" \
"CMakeFiles/digital_image.dir/threshold.cpp.obj" \
"CMakeFiles/digital_image.dir/region.cpp.obj" \
"CMakeFiles/digital_image.dir/edgeDetection.cpp.obj" \
"CMakeFiles/digital_image.dir/houghTransform.cpp.obj" \
"CMakeFiles/digital_image.dir/regionLabel.cpp.obj" \
"CMakeFiles/digital_image.dir/extractContour.cpp.obj"

# External object files for target digital_image
digital_image_EXTERNAL_OBJECTS =

digital_image.exe: CMakeFiles/digital_image.dir/main.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/bmp.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/histogram.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/filter.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/transform.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/threshold.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/region.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/edgeDetection.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/houghTransform.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/regionLabel.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/extractContour.cpp.obj
digital_image.exe: CMakeFiles/digital_image.dir/build.make
digital_image.exe: CMakeFiles/digital_image.dir/linkLibs.rsp
digital_image.exe: CMakeFiles/digital_image.dir/objects1.rsp
digital_image.exe: CMakeFiles/digital_image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable digital_image.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\digital_image.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/digital_image.dir/build: digital_image.exe
.PHONY : CMakeFiles/digital_image.dir/build

CMakeFiles/digital_image.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\digital_image.dir\cmake_clean.cmake
.PHONY : CMakeFiles/digital_image.dir/clean

CMakeFiles/digital_image.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\C++Project\digital_image D:\Code\C++Project\digital_image D:\Code\C++Project\digital_image\cmake-build-debug D:\Code\C++Project\digital_image\cmake-build-debug D:\Code\C++Project\digital_image\cmake-build-debug\CMakeFiles\digital_image.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/digital_image.dir/depend

