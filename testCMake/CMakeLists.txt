cmake_minimum_required(VERSION 3.0)
project(learn_cmake)

# 包含头文件目录（建议使用绝对路径）
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 设置源文件（需要明确指定.cpp文件）
# 这种方式不会自动更新，如果目录下添加新文件，需要重新cmake
file(GLOB SRC_LIST 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

# 或者手动列出源文件
# set(SRC_LIST 
#     src/main.cpp
#     src/other.cpp
# )

# 创建可执行文件
add_executable(main ${SRC_LIST})