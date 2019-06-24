//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_GAME_OVER_STATE_H
#define SNAKE_GAME_GAME_OVER_STATE_H


#include <misc/Printer.h>
#include "state_base.h"

template <class InputDevice, class Transmitter>
class game_over_state : public state_base<InputDevice> {
public:
  game_over_state(InputDevice& input) :
    state_base<InputDevice>(input) {};
  ~game_over_state() = default;

  state action() override {
    cv::Mat mat(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));
    Printer::gameOver<Transmitter>(mat);

    while (true) {
      switch (this->input_.getInput()) {
        case input::start:
          return state::initial;

        case input::menu:
          return state::end;

        default:
          break;
      }
      Printer::show<Transmitter>(mat, 500);
    }
  }
};


#endif //SNAKE_GAME_GAME_OVER_STATE_H
