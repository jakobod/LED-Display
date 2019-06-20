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
  Gem gem_;
  Snake snake_;
  InputDevice input_;
  std::thread t_input_;
  cv::Point dir_;
  Transmitter client_;
  std::random_device dev_;
  std::mt19937 rng_;
  std::uniform_int_distribution<int> dist22_;
  std::uniform_int_distribution<int> dist12_;


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
    dist12_(0,12)
  {
    cv::namedWindow("gamePane", cv::WINDOW_NORMAL);
  }

  ~SnakeGame() {
    input_.stop();
    t_input_.join();
  };

  bool loop() {
    if (!gem_)
      gem_ = Gem(cv::Point(dist22_(rng_), dist12_(rng_)));

    input d = input_.getInput();
    switch (d) {
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

    cv::Mat pane(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));
    if(!snake_.step(dir_, gem_)) {
      Printer::gameOver(pane, client_);
      return false; // should display gameOver msg
    }
    gem_.printTo(pane, Color::YELLOW);
    snake_.printTo(pane, Color::RED);

    Printer::show(pane, client_, 500);
    return true;
  }
};



#endif //XBOX_CONTROLLER_SNAKEGAME_H
