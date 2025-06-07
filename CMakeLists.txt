cmake_minimum_required(VERSION 3.9)
project(chat)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/server)
include_directories(${PROJECT_SOURCE_DIR}/include/server/db)
include_directories(${PROJECT_SOURCE_DIR}/thirdparty)

#加载子目录,去该目录找cmakelists文件
add_subdirectory(src)