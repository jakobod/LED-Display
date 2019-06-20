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

template<class InputDevice, class Transmitter>
class SnakeGame {
  InputDevice input_;
  std::thread t_input_;
  Transmitter client_;
  bool running_;

public:
  SnakeGame(std::string host, std::string port) :
    gem_(cv::Point(13,2)),
    snake_({cv::Point(13,5)}, cv::Size(23,13)),
    input_(),
    t_input_(std::ref(input_)),
    dir_(1,0),
    client_(std::move(host), std::move(port)),
    dev_(),
    rng_(dev_()),
    dist22_(0,22),
    dist12_(0,12),
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

    }
  }
};



#endif //XBOX_CONTROLLER_SNAKEGAME_H
