cmake_minimum_required(VERSION 3.13)
project(rosterer)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCE_FILES src/main.cpp src/InitialRosterManager.cpp src/Solution.cpp src/Objective.cpp src/MoveGenerator.cpp src/Staff.cpp)
set(CMAKE_BUILD_TYPE Debug)

include_directories("src")

add_executable(rosterer ${SOURCE_FILES})

target_link_libraries(rosterer ${CONAN_LIBS})