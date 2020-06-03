cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

file(GLOB_RECURSE SOURCES *.cpp *.h)

# The main program
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
