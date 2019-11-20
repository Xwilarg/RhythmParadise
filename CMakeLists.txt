cmake_minimum_required(VERSION 3.1)
project(RythmHero)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

if(MSVC)
    SET(CMAKE_CXX_FLAGS "/W4 /EHsc")
else()
    SET(CMAKE_CXX_FLAGS "-Wall -Wextra")
endif()

include_directories(inc)
add_executable(RythmHero
    src/main.cpp
    src/AClickableGameObject.cpp
    src/AGameObject.cpp
    src/Button.cpp
    src/InputField.cpp
    src/MusicLoader.cpp
    src/ResourceLoader.cpp
    src/Scene.cpp
    src/SceneLoader.cpp)
target_link_libraries(RythmHero ${CONAN_LIBS})