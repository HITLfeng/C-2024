# CMake最低版本 建议写
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 指定项目名称 （版本 备注 语言...）
project(test1demo)

# 带调试信息
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# CMakeLists.txt 文件所在路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 搜索 lib 目录下的源文件 CMAKE_CURRENT_SOURCE_DIR 同 PROJECT_SOURCE_DIR
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/lib SRC_LIST)
# message("SRC_LIST: ${SRC_LIST}")
# message("============================")
list(REMOVE_ITEM SRC_LIST /root/C-2024/Linux/IO/test1/lib/server.c)
# message("SRC_LIST: ${SRC_LIST}")

add_executable(main test1.c ${SRC_LIST})
add_executable(server lib/server.c)

target_link_libraries(main pthread rt)
target_link_libraries(server pthread)
# 执行 cmake + 路径 （CMakeLists.txt 文件所在路径）