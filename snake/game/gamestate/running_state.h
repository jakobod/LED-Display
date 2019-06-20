//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_RUNNING_STATE_H
#define SNAKE_GAME_RUNNING_STATE_H


#include <game/Gem.h>
#include <game/Snake.h>
#include "state_base.h"

class running_state : public state_base {
  Gem gem_;
  Snake snake_;
  cv::Point dir_;


public:
  running_state();

  running_state(const Gem& gem);

  ~running_state() = default;

  void action(input in, cv::Mat& mat) override;
};


#endif //SNAKE_GAME_RUNNING_STATE_H
