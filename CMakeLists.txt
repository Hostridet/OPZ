cmake_minimum_required(VERSION 3.17)
project(opz)

enable_testing()

add_definitions(-std=gnu++17 -U__STRICT_ANSI__)

set(LINKER_FLAGS1 -lcygwin)
set(LINKER_FLAGS2 -lSDL2main)
set(LINKER_FLAGS3 -lSDL2)
set(LINKER_FLAGS4 -mwindows)

add_subdirectory(googletest)

include_directories(tests)
include_directories(googletest/googletest/include)

set(SOURCE_FILES opz.cpp)
set(CMAKE_CXX_STANDARD 14)

add_executable(opz main.cpp opz.cpp opz.h)
add_executable(tests tests.cpp ${SOURCE_FILES})

target_link_libraries(tests gtest)