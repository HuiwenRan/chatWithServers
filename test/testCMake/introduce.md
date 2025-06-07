# 1. 文件目录结构
1.1 bin：存放可执行文件
1.2 lib：存放库文件
1.3 include：存放头文件
1.4 src：存放源代码
1.5 build：存放编译生成的文件
1.6 example：存放测试代码
1.7 thrid_party：存放第三方库
1.8 CMakeLists.txt：CMake配置文件
1.9 autobuild.sh：自动构建脚本

# 2. 环境变量说明
2.1 CMAKE_SOURCE_DIR：顶级CMakeLists.txt所在的目录，通常是项目根目录
2.2 CMAKE_BINARY_DIR：指向构建目录,运行cmake时的地方