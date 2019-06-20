//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_GAME_OVER_STATE_H
#define SNAKE_GAME_GAME_OVER_STATE_H


#include "state_base.h"

class game_over_state : public state_base {
  int counter;
public:
  game_over_state();
  ~game_over_state() override = default;

  state_base* action(input in, cv::Mat& mat) override;
};


#endif //SNAKE_GAME_GAME_OVER_STATE_H
