//
// Created by boss on 6/19/19.
//

#include "input/input_base.h"

input_base::input_base() :
  running_(true),
  input_(input::none) {}

void input_base::stop() {
  running_ = false;
}

input input_base::getInput() {
  return input_;
}


