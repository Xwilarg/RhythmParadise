cmake_minimum_required(VERSION 3.1)
project(RythmHero)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(inc)
add_executable(RythmHero
    src/main.cpp
    src/Scene.cpp
    src/AClickableGameObject.cpp)
target_link_libraries(RythmHero ${CONAN_LIBS})