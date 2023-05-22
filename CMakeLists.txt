cmake_minimum_required(VERSION 3.20)
project(uri)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
include_directories(include)


add_executable(uri src/uri.cpp test/UriTests.cpp) 
target_compile_options(uri PRIVATE -Wall -Wextra -O2 -march=native -mtune=native)
target_link_libraries(uri gtest)