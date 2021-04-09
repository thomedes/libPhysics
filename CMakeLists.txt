cmake_minimum_required (VERSION 3.16.0)

project(units)

add_library(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/si.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/constants.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
