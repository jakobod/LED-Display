//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_INITIAL_STATE_H
#define SNAKE_GAME_INITIAL_STATE_H


#include "state_base.h"

class initial_state : public state_base {
public:
  initial_state();
  ~initial_state() = default;

  state_base* action(input in, cv::Mat& mat) override;
};


#endif //SNAKE_GAME_INITIAL_STATE_H
