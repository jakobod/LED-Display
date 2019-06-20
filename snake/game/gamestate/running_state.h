//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_RUNNING_STATE_H
#define SNAKE_GAME_RUNNING_STATE_H

#include "state_base.h"
#include "game_over_state.h"
#include <game/Gem.h>
#include <game/Snake.h>
#include <misc/Printer.h>
#include <misc/Color.h>
#include <random>

class running_state : public state_base {
  Gem gem_;
  Snake snake_;
  cv::Point dir_;
  std::random_device dev_;
  std::mt19937 rng_;
  std::uniform_int_distribution<std::mt19937::result_type> dist12_;
  std::uniform_int_distribution<std::mt19937::result_type> dist22_;

public:
  running_state();
  ~running_state() override = default;

  state_base* action(input in, cv::Mat& mat) override {
    if (!gem_)
      gem_ = Gem(cv::Point(dist22_(rng_), dist12_(rng_)));

    switch (in) {
      case input::up:
        dir_ = cv::Point(0, -1);
        break;

      case input::down:
        dir_ = cv::Point(0, 1);
        break;

      case input::left:
        dir_ = cv::Point(-1, 0);
        break;

      case input::right:
        dir_ = cv::Point(1, 0);
        break;

      default:
        break;
    }

    if (!snake_.step(dir_, gem_)) {
      return new game_over_state;
    }
    gem_.printTo(mat, Color::YELLOW);
    snake_.printTo(mat, Color::RED);
    return this;
  }
};


#endif //SNAKE_GAME_RUNNING_STATE_H
