cmake_minimum_required(VERSION 3.14)
project(snake_game)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-Wall -Wpedantic -g")

include_directories(gamepad)
include_directories(snake)
include_directories(snake/com)
include_directories(snake/game)
include_directories(snake/input)
include_directories(snake/misc)

file(GLOB SRC_FILES src/*.cpp)
file(GLOB GAMEPAD_SRC_FILES gamepad/*.c)

message(STATUS "SRC_FILES: ${SRC_FILES}")
message(STATUS "GAMEPAD_SRC_FILES ${GAMEPAD_SRC_FILES}")

find_package(udev REQUIRED)
include_directories(${UDEV_INCLUDE_DIRS})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(
  snake_game
  ${SRC_FILES}
  ${GAMEPAD_SRC_FILES}
  main.cpp
    snake/misc/Color.cpp snake/misc/Color.h)

target_link_libraries(snake_game
  ${UDEV_LIBRARIES}
  ${CURSES_LIBRARIES}
  ${OpenCV_LIBS}
  m # this is for math calls
)