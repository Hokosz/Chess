cmake_minimum_required(VERSION 3.30.5)
project(CLionGraphicsKit)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_library(graphics graphics.cpp
        widgets.cpp
        widgets.hpp)

include_directories(include)
link_directories(lib)

target_link_libraries( graphics SDL2 SDL2.dll SDL2main SDL2_ttf SDL2_ttf.dll)


add_executable(CLionGraphicsKit main.cpp
        widgets.cpp
        widgets.hpp
        myapp.cpp
        myapp.hpp
        button.cpp
        dropdown.cpp
        screen.cpp
        screen.hpp
        piece.cpp
        piece.hpp
        game.cpp
        game.hpp
)
target_link_libraries(CLionGraphicsKit graphics)
