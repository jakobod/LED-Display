//
// Created by boss on 6/18/19.
//

#ifndef SNAKE_GAME_XBOX_CONTROLLER_H
#define SNAKE_GAME_XBOX_CONTROLLER_H


#include "input_base.h"

class xbox_controller : public input_base {
public:
  xbox_controller();
  ~xbox_controller() = default;

  void operator()() override;
};


#endif //SNAKE_GAME_XBOX_CONTROLLER_H
