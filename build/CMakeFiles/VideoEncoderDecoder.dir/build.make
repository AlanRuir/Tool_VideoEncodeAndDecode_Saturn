# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/holo/apps/VideoEncoderAndDecoder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/holo/apps/VideoEncoderAndDecoder/build

# Include any dependencies generated for this target.
include CMakeFiles/VideoEncoderDecoder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VideoEncoderDecoder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VideoEncoderDecoder.dir/flags.make

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o: CMakeFiles/VideoEncoderDecoder.dir/flags.make
CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o: ../src/video/image_decoder_h26x.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/holo/apps/VideoEncoderAndDecoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o -c /home/holo/apps/VideoEncoderAndDecoder/src/video/image_decoder_h26x.cpp

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/holo/apps/VideoEncoderAndDecoder/src/video/image_decoder_h26x.cpp > CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.i

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/holo/apps/VideoEncoderAndDecoder/src/video/image_decoder_h26x.cpp -o CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.s

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o.requires:

.PHONY : CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o.requires

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o.provides: CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o.requires
	$(MAKE) -f CMakeFiles/VideoEncoderDecoder.dir/build.make CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o.provides.build
.PHONY : CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o.provides

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o.provides.build: CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o


CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o: CMakeFiles/VideoEncoderDecoder.dir/flags.make
CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o: ../src/video/image_encoder_h26x.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/holo/apps/VideoEncoderAndDecoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o -c /home/holo/apps/VideoEncoderAndDecoder/src/video/image_encoder_h26x.cpp

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/holo/apps/VideoEncoderAndDecoder/src/video/image_encoder_h26x.cpp > CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.i

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/holo/apps/VideoEncoderAndDecoder/src/video/image_encoder_h26x.cpp -o CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.s

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o.requires:

.PHONY : CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o.requires

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o.provides: CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o.requires
	$(MAKE) -f CMakeFiles/VideoEncoderDecoder.dir/build.make CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o.provides.build
.PHONY : CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o.provides

CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o.provides.build: CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o


CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o: CMakeFiles/VideoEncoderDecoder.dir/flags.make
CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o: ../src/video/video_decoder_decoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/holo/apps/VideoEncoderAndDecoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o -c /home/holo/apps/VideoEncoderAndDecoder/src/video/video_decoder_decoder.cpp

CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/holo/apps/VideoEncoderAndDecoder/src/video/video_decoder_decoder.cpp > CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.i

CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/holo/apps/VideoEncoderAndDecoder/src/video/video_decoder_decoder.cpp -o CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.s

CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o.requires:

.PHONY : CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o.requires

CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o.provides: CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o.requires
	$(MAKE) -f CMakeFiles/VideoEncoderDecoder.dir/build.make CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o.provides.build
.PHONY : CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o.provides

CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o.provides.build: CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o


CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o: CMakeFiles/VideoEncoderDecoder.dir/flags.make
CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/holo/apps/VideoEncoderAndDecoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o -c /home/holo/apps/VideoEncoderAndDecoder/src/main.cpp

CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/holo/apps/VideoEncoderAndDecoder/src/main.cpp > CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.i

CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/holo/apps/VideoEncoderAndDecoder/src/main.cpp -o CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.s

CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o.requires

CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o.provides: CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/VideoEncoderDecoder.dir/build.make CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o.provides

CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o.provides.build: CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o


# Object files for target VideoEncoderDecoder
VideoEncoderDecoder_OBJECTS = \
"CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o" \
"CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o" \
"CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o" \
"CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o"

# External object files for target VideoEncoderDecoder
VideoEncoderDecoder_EXTERNAL_OBJECTS =

bin/VideoEncoderDecoder: CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o
bin/VideoEncoderDecoder: CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o
bin/VideoEncoderDecoder: CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o
bin/VideoEncoderDecoder: CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o
bin/VideoEncoderDecoder: CMakeFiles/VideoEncoderDecoder.dir/build.make
bin/VideoEncoderDecoder: /usr/lib/x86_64-linux-gnu/libavcodec.so
bin/VideoEncoderDecoder: /usr/lib/x86_64-linux-gnu/libavformat.so
bin/VideoEncoderDecoder: /usr/lib/x86_64-linux-gnu/libavfilter.so
bin/VideoEncoderDecoder: /usr/lib/x86_64-linux-gnu/libavutil.so
bin/VideoEncoderDecoder: CMakeFiles/VideoEncoderDecoder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/holo/apps/VideoEncoderAndDecoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin/VideoEncoderDecoder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VideoEncoderDecoder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VideoEncoderDecoder.dir/build: bin/VideoEncoderDecoder

.PHONY : CMakeFiles/VideoEncoderDecoder.dir/build

CMakeFiles/VideoEncoderDecoder.dir/requires: CMakeFiles/VideoEncoderDecoder.dir/src/video/image_decoder_h26x.cpp.o.requires
CMakeFiles/VideoEncoderDecoder.dir/requires: CMakeFiles/VideoEncoderDecoder.dir/src/video/image_encoder_h26x.cpp.o.requires
CMakeFiles/VideoEncoderDecoder.dir/requires: CMakeFiles/VideoEncoderDecoder.dir/src/video/video_decoder_decoder.cpp.o.requires
CMakeFiles/VideoEncoderDecoder.dir/requires: CMakeFiles/VideoEncoderDecoder.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/VideoEncoderDecoder.dir/requires

CMakeFiles/VideoEncoderDecoder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VideoEncoderDecoder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VideoEncoderDecoder.dir/clean

CMakeFiles/VideoEncoderDecoder.dir/depend:
	cd /home/holo/apps/VideoEncoderAndDecoder/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/holo/apps/VideoEncoderAndDecoder /home/holo/apps/VideoEncoderAndDecoder /home/holo/apps/VideoEncoderAndDecoder/build /home/holo/apps/VideoEncoderAndDecoder/build /home/holo/apps/VideoEncoderAndDecoder/build/CMakeFiles/VideoEncoderDecoder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VideoEncoderDecoder.dir/depend

