cmake_minimum_required(VERSION 3.14)
project(XBox_controller)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lc -lm -lcurses")

find_package(udev REQUIRED)
include_directories(${UDEV_INCLUDE_DIRS})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})
include_directories(gamepad)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(XBox_controller
  main.cpp
  UDP_Client.cpp
  gamepad/gamepad.c
    Snake.cpp Snake.h Gem.cpp Gem.h Printer.cpp Printer.h)

target_link_libraries(XBox_controller
  ${UDEV_LIBRARIES}
  ${CURSES_LIBRARIES}
  ${OpenCV_LIBS}
  m # this is for math calls
)