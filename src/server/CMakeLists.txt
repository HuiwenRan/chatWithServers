# 不会递归包含
aux_source_directory(. SRC_LIST)

add_executable(server ${SRC_LIST})
#指定可执行文件需要依赖的库文件
target_link_directories(server muduo_net muduo_base pthread)