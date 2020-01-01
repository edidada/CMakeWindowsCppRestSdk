# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project("CMakeProject1")

# 将源代码添加到此项目的可执行文件。
add_executable (CMakeProject1 "CMakeProject1.cpp" "src/MyClass.cpp")

# TODO: 如有需要，请添加测试并安装目标。

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(CMakeProject1 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain CMakeProject1)