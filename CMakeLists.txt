cmake_minimum_required(VERSION 3.29)
project(OpenGL)

link_directories("/usr/lib")
link_directories("/usr/local/lib")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(GLFW3_INCLUDE_DIR "/usr/include")
set(GLFW3_LIBRARY "/usr/lib/libglfw.so")

set(CMAKE_CXX_STANDARD 17)

find_package(GLFW3 REQUIRED)

include_directories(
        ${GLFW3_INCLUDE_DIRS}
        "${CMAKE_CURRENT_LIST_DIR}/include"
)

add_executable(OpenGL main.cpp
        src/glad.c
)

target_link_libraries(OpenGL
        ${GLFW3_LIBRARY}
)

