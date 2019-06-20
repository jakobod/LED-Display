//
// Created by boss on 6/19/19.
//

#include "keyboard.h"
#include <iostream>
#include <ncurses.h>

keyboard::keyboard() : input_base() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
}

void keyboard::operator()() {
  while (running_) {
    auto c = getch();
    switch(c) {
      case KEY_UP:
        input_ = input::up;
        break;
      case KEY_DOWN:
        input_ = input::down;
        break;
      case KEY_LEFT:
        input_ = input::left;
        break;
      case KEY_RIGHT:
        input_ = input::right;
        break;
      case 10:
        input_ = input::start;
        break;
      case 27:
        input_ = input::menu;
        break;

      default:
        std::cout << "unknown input = " << c << std::endl;
        break;
    }
  }
}

keyboard::~keyboard() {
  refresh();
  getch();
  endwin();
}

