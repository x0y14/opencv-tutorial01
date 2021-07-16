cmake_minimum_required(VERSION 3.19)
project(opencv_tutorial01)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(opencv_tutorial01 main.cpp)

target_link_libraries(opencv_tutorial01 PRIVATE ${OpenCV_LIBS})