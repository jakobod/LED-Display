//
// Created by boss on 6/18/19.
//

#ifndef XBOX_CONTROLLER_SNAKEGAME_H
#define XBOX_CONTROLLER_SNAKEGAME_H

#include <misc/Color.h>
#include <cv.hpp>
#include <misc/Printer.h>
#include <thread>
#include "Gem.h"
#include "Snake.h"
#include "input/input_base.h"
#include <random>
#include <game/gamestate/state_base.h>
#include <game/gamestate/running_state.h>

template<class InputDevice, class Transmitter>
class SnakeGame {
  state_base* state_;
  InputDevice input_;
  std::thread t_input_;
  Transmitter client_;
  bool running_;

public:
  SnakeGame(std::string host, std::string port) :
    state_(new running_state),
    input_(),
    t_input_(std::ref(input_)),
    client_(std::move(host), std::move(port)),
    running_(true)
  {
    cv::namedWindow("gamePane", cv::WINDOW_NORMAL);
  }

  ~SnakeGame() {
    input_.stop();
    t_input_.join();
  };

  void  operator()() {
    while (running_) {
      cv::Mat field(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));
      auto new_state = state_->action(input_.getInput(), field);
      if (new_state != state_) {
        delete state_;
        state_ = new_state;
      }
      if (state_ == nullptr) {
        running_ = false;
      }
      Printer::show(field, client_, 500);
    }
  }
};



#endif //XBOX_CONTROLLER_SNAKEGAME_H
