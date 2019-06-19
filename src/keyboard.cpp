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
    switch(getch()) {
      case KEY_UP:
        input_ = up;
        break;
      case KEY_DOWN:
        input_ = down;
        break;
      case KEY_LEFT:
        input_ = left;
        break;
      case KEY_RIGHT:
        input_ = right;
        break;
      default:
        break;
    }
  }
}

keyboard::~keyboard() {
  refresh();
  getch();
  endwin();
}

