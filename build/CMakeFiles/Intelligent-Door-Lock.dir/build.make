# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Intelligent-Door-Lock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Intelligent-Door-Lock/build

# Include any dependencies generated for this target.
include CMakeFiles/Intelligent-Door-Lock.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Intelligent-Door-Lock.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Intelligent-Door-Lock.dir/flags.make

CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.o: CMakeFiles/Intelligent-Door-Lock.dir/flags.make
CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.o -c /home/pi/Intelligent-Door-Lock/src/main.cpp

CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Intelligent-Door-Lock/src/main.cpp > CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.i

CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Intelligent-Door-Lock/src/main.cpp -o CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.s

CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.o: CMakeFiles/Intelligent-Door-Lock.dir/flags.make
CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.o: ../src/welcome.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.o -c /home/pi/Intelligent-Door-Lock/src/welcome.cpp

CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Intelligent-Door-Lock/src/welcome.cpp > CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.i

CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Intelligent-Door-Lock/src/welcome.cpp -o CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.s

CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.o: CMakeFiles/Intelligent-Door-Lock.dir/flags.make
CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.o: ../src/arcface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.o -c /home/pi/Intelligent-Door-Lock/src/arcface.cpp

CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Intelligent-Door-Lock/src/arcface.cpp > CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.i

CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Intelligent-Door-Lock/src/arcface.cpp -o CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.s

CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.o: CMakeFiles/Intelligent-Door-Lock.dir/flags.make
CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.o: ../src/live.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.o -c /home/pi/Intelligent-Door-Lock/src/live.cpp

CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Intelligent-Door-Lock/src/live.cpp > CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.i

CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Intelligent-Door-Lock/src/live.cpp -o CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.s

CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.o: CMakeFiles/Intelligent-Door-Lock.dir/flags.make
CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.o: ../src/livefacereco.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.o -c /home/pi/Intelligent-Door-Lock/src/livefacereco.cpp

CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Intelligent-Door-Lock/src/livefacereco.cpp > CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.i

CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Intelligent-Door-Lock/src/livefacereco.cpp -o CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.s

CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.o: CMakeFiles/Intelligent-Door-Lock.dir/flags.make
CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.o: ../src/mtcnn_new.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.o -c /home/pi/Intelligent-Door-Lock/src/mtcnn_new.cpp

CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Intelligent-Door-Lock/src/mtcnn_new.cpp > CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.i

CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Intelligent-Door-Lock/src/mtcnn_new.cpp -o CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.s

CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.o: CMakeFiles/Intelligent-Door-Lock.dir/flags.make
CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.o: ../src/parallel_video_capture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.o -c /home/pi/Intelligent-Door-Lock/src/parallel_video_capture.cpp

CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Intelligent-Door-Lock/src/parallel_video_capture.cpp > CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.i

CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Intelligent-Door-Lock/src/parallel_video_capture.cpp -o CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.s

CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.o: CMakeFiles/Intelligent-Door-Lock.dir/flags.make
CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.o: Intelligent-Door-Lock_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.o -c /home/pi/Intelligent-Door-Lock/build/Intelligent-Door-Lock_autogen/mocs_compilation.cpp

CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Intelligent-Door-Lock/build/Intelligent-Door-Lock_autogen/mocs_compilation.cpp > CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.i

CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Intelligent-Door-Lock/build/Intelligent-Door-Lock_autogen/mocs_compilation.cpp -o CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.s

# Object files for target Intelligent-Door-Lock
Intelligent__Door__Lock_OBJECTS = \
"CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.o" \
"CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.o" \
"CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.o" \
"CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.o" \
"CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.o" \
"CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.o" \
"CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.o" \
"CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.o"

# External object files for target Intelligent-Door-Lock
Intelligent__Door__Lock_EXTERNAL_OBJECTS =

Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/src/main.cpp.o
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/src/welcome.cpp.o
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/src/arcface.cpp.o
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/src/live.cpp.o
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/src/livefacereco.cpp.o
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/src/mtcnn_new.cpp.o
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/src/parallel_video_capture.cpp.o
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/Intelligent-Door-Lock_autogen/mocs_compilation.cpp.o
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/build.make
Intelligent-Door-Lock: /usr/local/lib/libopencv_gapi.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_stitching.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_aruco.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_bgsegm.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_bioinspired.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_ccalib.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_dnn_objdetect.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_dnn_superres.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_dpm.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_face.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_freetype.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_fuzzy.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_hfs.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_img_hash.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_intensity_transform.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_line_descriptor.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_mcc.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_quality.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_rapid.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_reg.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_rgbd.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_saliency.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_stereo.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_structured_light.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_superres.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_surface_matching.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_tracking.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_videostab.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_xfeatures2d.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_xobjdetect.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_xphoto.so.4.5.0
Intelligent-Door-Lock: /usr/lib/aarch64-linux-gnu/libQt5Widgets.so.5.11.3
Intelligent-Door-Lock: /usr/local/lib/libwiringPi.so
Intelligent-Door-Lock: /usr/local/lib/libopencv_shape.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_highgui.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_datasets.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_plot.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_text.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_dnn.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_ml.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_phase_unwrapping.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_optflow.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_ximgproc.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_video.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_videoio.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_imgcodecs.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_objdetect.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_calib3d.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_features2d.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_flann.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_photo.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_imgproc.so.4.5.0
Intelligent-Door-Lock: /usr/local/lib/libopencv_core.so.4.5.0
Intelligent-Door-Lock: /usr/lib/aarch64-linux-gnu/libQt5Gui.so.5.11.3
Intelligent-Door-Lock: /usr/lib/aarch64-linux-gnu/libQt5Core.so.5.11.3
Intelligent-Door-Lock: CMakeFiles/Intelligent-Door-Lock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Intelligent-Door-Lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Intelligent-Door-Lock"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Intelligent-Door-Lock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Intelligent-Door-Lock.dir/build: Intelligent-Door-Lock

.PHONY : CMakeFiles/Intelligent-Door-Lock.dir/build

CMakeFiles/Intelligent-Door-Lock.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Intelligent-Door-Lock.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Intelligent-Door-Lock.dir/clean

CMakeFiles/Intelligent-Door-Lock.dir/depend:
	cd /home/pi/Intelligent-Door-Lock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Intelligent-Door-Lock /home/pi/Intelligent-Door-Lock /home/pi/Intelligent-Door-Lock/build /home/pi/Intelligent-Door-Lock/build /home/pi/Intelligent-Door-Lock/build/CMakeFiles/Intelligent-Door-Lock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Intelligent-Door-Lock.dir/depend
