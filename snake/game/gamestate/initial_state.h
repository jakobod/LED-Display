//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_INITIAL_STATE_H
#define SNAKE_GAME_INITIAL_STATE_H


#include "state_base.h"

template <class InputDevice, class Transmitter>
class initial_state : public state_base<InputDevice> {
public:
  initial_state(InputDevice& input) :
    state_base<InputDevice>(input) {}
  ~initial_state() = default;

  state action() override {
    cv::Mat mat(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));
    Printer::printString(mat, "press", cv::Point(1,1), Color::GREEN);
    Printer::printString(mat, "start", cv::Point(1,7), Color::GREEN);
    viewer<Transmitter>::show(mat);

    while (this->input_.getInput() != input::start) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return state::running;
  }
};

#endif //SNAKE_GAME_INITIAL_STATE_H
