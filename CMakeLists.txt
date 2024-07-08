cmake_minimum_required(VERSION 3.27)
project(snake3d)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake3d src/main.cpp)

target_link_libraries(snake3d -lglew32 -lOpenGL32 -lfreeglut -lglu32)