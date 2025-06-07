# 不会递归包含
aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_SRC)

add_executable(server ${SRC_LIST} ${DB_SRC})
#指定可执行文件需要依赖的库文件
target_link_libraries(server muduo_net muduo_base mysqlclient pthread)