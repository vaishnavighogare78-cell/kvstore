# CMake reads this file and works out how to compile the project.
cmake_minimum_required(VERSION 3.16)
project(kvstore CXX)

# Use modern C++ (C++17).
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Show warnings - they help you catch mistakes early.
add_compile_options(-Wall -Wextra)

# The store itself is built once as a "library", so both the
# main program and the tests can use the same code.
add_library(kvstore_lib src/kvstore.cpp)
target_include_directories(kvstore_lib PUBLIC src)

# The interactive program you type commands into.
add_executable(kvstore src/main.cpp)
target_link_libraries(kvstore PRIVATE kvstore_lib)

# ---- Tests ----
# enable_testing() turns on CTest, CMake's test runner.
enable_testing()
add_executable(test_kvstore tests/test_kvstore.cpp)
target_link_libraries(test_kvstore PRIVATE kvstore_lib)
add_test(NAME kvstore_tests COMMAND test_kvstore)
