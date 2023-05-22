cmake_minimum_required(VERSION 3.20)
project(uri)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
include_directories(include)


 
add_library(uri src/uri.cpp)
add_executable(UriTest test/UriTests.cpp)
target_link_libraries(UriTest uri gtest)




target_compile_options(uri PRIVATE -Wall -Wextra -O2 -march=native -mtune=native)
