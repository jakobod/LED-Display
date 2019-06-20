//
// Created by boss on 6/20/19.
//

#include "running_state.h"

#include "misc/Printer.h"
#include "misc/Color.h"

void running_state::action(input in, cv::Mat& mat) {
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

  cv::Mat pane(cv::Size(23, 13), CV_8UC3, cv::Scalar(0, 0, 0));
  if (!snake_.step(dir_, gem_)) {
    Printer::gameOver(pane, client_);
  }
  gem_.printTo(pane, Color::YELLOW);
  snake_.printTo(pane, Color::RED);

  Printer::show(pane, client_, 500);
}

running_state::running_state(const Gem& gem) : gem_(gem) {}
