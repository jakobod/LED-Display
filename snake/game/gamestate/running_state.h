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

template<class InputDevice, class Transmitter>
class running_state : public state_base<InputDevice> {
  Gem gem_;
  Snake snake_;
  cv::Point dir_;

public:
  running_state(InputDevice& input) :
      state_base<InputDevice>(input),
      gem_(),
      snake_({cv::Point(13,5)}, cv::Size(23,13)),
      dir_(1,0)
  {}
  ~running_state() override = default;

  state action() override {
    while (true) {
      if (!gem_)
        gem_.reset();

      switch (this->input_.getInput()) {
        case input::up:
          dir_ = cv::Point(0,-1);
          break;

        case input::down:
          dir_ = cv::Point(0,1);
          break;

        case input::left:
          dir_ = cv::Point(-1,0);
          break;

        case input::right:
          dir_ = cv::Point(1,0);
          break;

        default:
          break;
      }

      if (!snake_.step(dir_, gem_)) {
        return state::game_over;
      }

      cv::Mat mat(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));
      gem_.printTo(mat, Color::YELLOW);
      snake_.printTo(mat, Color::RED);
      viewer<Transmitter>::show(mat);
      std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
  }

  void reset() override {
    snake_ = Snake({cv::Point(13,5)}, cv::Size(23,13));
    gem_.reset();
    dir_ = cv::Point(1,0);
  }
};


#endif //SNAKE_GAME_RUNNING_STATE_H
