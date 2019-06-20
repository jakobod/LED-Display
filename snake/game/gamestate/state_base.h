//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_STATE_BASE_H
#define SNAKE_GAME_STATE_BASE_H

#include <input/input_base.h>

class state_base {
public:
  state_base() = default;
  ~state_base() = default;

  virtual void action(input in) = 0;
};

#endif //SNAKE_GAME_STATE_BASE_H
