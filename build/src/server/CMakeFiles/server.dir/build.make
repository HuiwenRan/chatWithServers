# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/chat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/chat/build

# Include any dependencies generated for this target.
include src/server/CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/server/CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include src/server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/CMakeFiles/server.dir/flags.make

src/server/CMakeFiles/server.dir/chatservice.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/chatservice.cpp.o: /root/chat/src/server/chatservice.cpp
src/server/CMakeFiles/server.dir/chatservice.cpp.o: src/server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/server/CMakeFiles/server.dir/chatservice.cpp.o"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/server.dir/chatservice.cpp.o -MF CMakeFiles/server.dir/chatservice.cpp.o.d -o CMakeFiles/server.dir/chatservice.cpp.o -c /root/chat/src/server/chatservice.cpp

src/server/CMakeFiles/server.dir/chatservice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/chatservice.cpp.i"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/chat/src/server/chatservice.cpp > CMakeFiles/server.dir/chatservice.cpp.i

src/server/CMakeFiles/server.dir/chatservice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/chatservice.cpp.s"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/chat/src/server/chatservice.cpp -o CMakeFiles/server.dir/chatservice.cpp.s

src/server/CMakeFiles/server.dir/main.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/main.cpp.o: /root/chat/src/server/main.cpp
src/server/CMakeFiles/server.dir/main.cpp.o: src/server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/server/CMakeFiles/server.dir/main.cpp.o"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/server.dir/main.cpp.o -MF CMakeFiles/server.dir/main.cpp.o.d -o CMakeFiles/server.dir/main.cpp.o -c /root/chat/src/server/main.cpp

src/server/CMakeFiles/server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/main.cpp.i"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/chat/src/server/main.cpp > CMakeFiles/server.dir/main.cpp.i

src/server/CMakeFiles/server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/main.cpp.s"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/chat/src/server/main.cpp -o CMakeFiles/server.dir/main.cpp.s

src/server/CMakeFiles/server.dir/db/db.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/db/db.cpp.o: /root/chat/src/server/db/db.cpp
src/server/CMakeFiles/server.dir/db/db.cpp.o: src/server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/server/CMakeFiles/server.dir/db/db.cpp.o"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/server.dir/db/db.cpp.o -MF CMakeFiles/server.dir/db/db.cpp.o.d -o CMakeFiles/server.dir/db/db.cpp.o -c /root/chat/src/server/db/db.cpp

src/server/CMakeFiles/server.dir/db/db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/db/db.cpp.i"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/chat/src/server/db/db.cpp > CMakeFiles/server.dir/db/db.cpp.i

src/server/CMakeFiles/server.dir/db/db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/db/db.cpp.s"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/chat/src/server/db/db.cpp -o CMakeFiles/server.dir/db/db.cpp.s

src/server/CMakeFiles/server.dir/model/friendmodel.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/model/friendmodel.cpp.o: /root/chat/src/server/model/friendmodel.cpp
src/server/CMakeFiles/server.dir/model/friendmodel.cpp.o: src/server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/server/CMakeFiles/server.dir/model/friendmodel.cpp.o"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/server.dir/model/friendmodel.cpp.o -MF CMakeFiles/server.dir/model/friendmodel.cpp.o.d -o CMakeFiles/server.dir/model/friendmodel.cpp.o -c /root/chat/src/server/model/friendmodel.cpp

src/server/CMakeFiles/server.dir/model/friendmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/model/friendmodel.cpp.i"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/chat/src/server/model/friendmodel.cpp > CMakeFiles/server.dir/model/friendmodel.cpp.i

src/server/CMakeFiles/server.dir/model/friendmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/model/friendmodel.cpp.s"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/chat/src/server/model/friendmodel.cpp -o CMakeFiles/server.dir/model/friendmodel.cpp.s

src/server/CMakeFiles/server.dir/model/groupmodel.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/model/groupmodel.cpp.o: /root/chat/src/server/model/groupmodel.cpp
src/server/CMakeFiles/server.dir/model/groupmodel.cpp.o: src/server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/server/CMakeFiles/server.dir/model/groupmodel.cpp.o"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/server.dir/model/groupmodel.cpp.o -MF CMakeFiles/server.dir/model/groupmodel.cpp.o.d -o CMakeFiles/server.dir/model/groupmodel.cpp.o -c /root/chat/src/server/model/groupmodel.cpp

src/server/CMakeFiles/server.dir/model/groupmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/model/groupmodel.cpp.i"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/chat/src/server/model/groupmodel.cpp > CMakeFiles/server.dir/model/groupmodel.cpp.i

src/server/CMakeFiles/server.dir/model/groupmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/model/groupmodel.cpp.s"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/chat/src/server/model/groupmodel.cpp -o CMakeFiles/server.dir/model/groupmodel.cpp.s

src/server/CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o: /root/chat/src/server/model/offlinemsgmodel.cpp
src/server/CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o: src/server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/server/CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o -MF CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o.d -o CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o -c /root/chat/src/server/model/offlinemsgmodel.cpp

src/server/CMakeFiles/server.dir/model/offlinemsgmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/model/offlinemsgmodel.cpp.i"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/chat/src/server/model/offlinemsgmodel.cpp > CMakeFiles/server.dir/model/offlinemsgmodel.cpp.i

src/server/CMakeFiles/server.dir/model/offlinemsgmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/model/offlinemsgmodel.cpp.s"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/chat/src/server/model/offlinemsgmodel.cpp -o CMakeFiles/server.dir/model/offlinemsgmodel.cpp.s

src/server/CMakeFiles/server.dir/model/usermodel.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/model/usermodel.cpp.o: /root/chat/src/server/model/usermodel.cpp
src/server/CMakeFiles/server.dir/model/usermodel.cpp.o: src/server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/server/CMakeFiles/server.dir/model/usermodel.cpp.o"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/server.dir/model/usermodel.cpp.o -MF CMakeFiles/server.dir/model/usermodel.cpp.o.d -o CMakeFiles/server.dir/model/usermodel.cpp.o -c /root/chat/src/server/model/usermodel.cpp

src/server/CMakeFiles/server.dir/model/usermodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/model/usermodel.cpp.i"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/chat/src/server/model/usermodel.cpp > CMakeFiles/server.dir/model/usermodel.cpp.i

src/server/CMakeFiles/server.dir/model/usermodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/model/usermodel.cpp.s"
	cd /root/chat/build/src/server && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/chat/src/server/model/usermodel.cpp -o CMakeFiles/server.dir/model/usermodel.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/chatservice.cpp.o" \
"CMakeFiles/server.dir/main.cpp.o" \
"CMakeFiles/server.dir/db/db.cpp.o" \
"CMakeFiles/server.dir/model/friendmodel.cpp.o" \
"CMakeFiles/server.dir/model/groupmodel.cpp.o" \
"CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o" \
"CMakeFiles/server.dir/model/usermodel.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

/root/chat/bin/server: src/server/CMakeFiles/server.dir/chatservice.cpp.o
/root/chat/bin/server: src/server/CMakeFiles/server.dir/main.cpp.o
/root/chat/bin/server: src/server/CMakeFiles/server.dir/db/db.cpp.o
/root/chat/bin/server: src/server/CMakeFiles/server.dir/model/friendmodel.cpp.o
/root/chat/bin/server: src/server/CMakeFiles/server.dir/model/groupmodel.cpp.o
/root/chat/bin/server: src/server/CMakeFiles/server.dir/model/offlinemsgmodel.cpp.o
/root/chat/bin/server: src/server/CMakeFiles/server.dir/model/usermodel.cpp.o
/root/chat/bin/server: src/server/CMakeFiles/server.dir/build.make
/root/chat/bin/server: src/server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/root/chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable /root/chat/bin/server"
	cd /root/chat/build/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/CMakeFiles/server.dir/build: /root/chat/bin/server
.PHONY : src/server/CMakeFiles/server.dir/build

src/server/CMakeFiles/server.dir/clean:
	cd /root/chat/build/src/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : src/server/CMakeFiles/server.dir/clean

src/server/CMakeFiles/server.dir/depend:
	cd /root/chat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/chat /root/chat/src/server /root/chat/build /root/chat/build/src/server /root/chat/build/src/server/CMakeFiles/server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/server/CMakeFiles/server.dir/depend

