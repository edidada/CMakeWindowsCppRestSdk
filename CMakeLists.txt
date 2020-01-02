# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# SET(CMAKE_TOOLCHAIN_FILE "D:\vcpkg\scripts\buildsystems\vcpkg.cmake")

project("CMakeProject1")
# project("CMakeProjectPoco")

# 将源代码添加到此项目的可执行文件。
add_executable (CMakeProject1 "CMakeProject1.cpp" "src/MyClass.cpp")
add_executable (CMakeProject1Gtest "src/samples/sample1.cc")
add_executable (CMakeProject1RestCpp "src/cpp_rest.cc")

# TODO: 如有需要，请添加测试并安装目标。

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(CMakeProject1Gtest PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain CMakeProject1Gtest)

find_package(cpprestsdk REQUIRED)

target_link_libraries(CMakeProject1RestCpp PRIVATE cpprestsdk::cpprest)

# find_package(cpp-netlib CONFIG REQUIRED)
# target_link_libraries(CMakeProject1 PRIVATE cppnetlib-uri cppnetlib-server-parsers cppnetlib-client-connections)

# find_package(Poco CONFIG REQUIRED)
# target_link_libraries(CMakeProjectPoco PRIVATE Poco::Net Poco::XML Poco::Zip)