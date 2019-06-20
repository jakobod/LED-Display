//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_STATE_BASE_H
#define SNAKE_GAME_STATE_BASE_H

#include <input/input_base.h>
#include <opencv2/core/mat.hpp>

class state_base {
public:
  state_base() = default;
  ~state_base() = default;

  virtual void action(input in, cv::Mat& mat) = 0;
};

#endif //SNAKE_GAME_STATE_BASE_H
