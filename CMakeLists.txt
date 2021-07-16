cmake_minimum_required(VERSION 3.19)
project(opencv_tutorial01)

set(CMAKE_CXX_STANDARD 14)


if (APPLE)
    find_package(OpenCV REQUIRED)
    add_executable(opencv_tutorial01 main.cpp)
    target_link_libraries(opencv_tutorial01 PRIVATE ${OpenCV_LIBS})
elseif(UNIX AND NOT APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(OPENCV5 opencv5 REQUIRED)
    include_directories(${OPENCV5_INCLUDE_DIRS})
    add_executable(opencv_tutorial01 main.cpp)
    target_link_libraries(opencv_tutorial01 PRIVATE ${OpenCV_LIBRARIES})
endif()