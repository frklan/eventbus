cmake_minimum_required(VERSION 3.1)

project(ebus)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Add files
file(GLOB_RECURSE SOURCES src/*.cpp)

# set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Woverloaded-virtual -pedantic")
set(CMAKE_CXX_FLAGS "-Weverything")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#Define the executable
add_executable(
    ${PROJECT_NAME} 
    ${SOURCES} 
)
target_link_libraries(${PROJECT_NAME} )