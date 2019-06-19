//
// Created by boss on 6/19/19.
//

#ifndef SNAKE_GAME_KEYBOARD_H
#define SNAKE_GAME_KEYBOARD_H

#include "input/input_base.h"

class keyboard : public input_base {
public:
  keyboard();
  ~keyboard();

  void operator()() override;
};


#endif //SNAKE_GAME_KEYBOARD_H
