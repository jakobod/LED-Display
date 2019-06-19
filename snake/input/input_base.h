//
// Created by boss on 6/18/19.
//

#ifndef XBOX_CONTROLLER_INPUT_BASE_H
#define XBOX_CONTROLLER_INPUT_BASE_H

enum direction {
  up,
  down,
  left,
  right,
  none,
};

class input_base {
protected:
  bool running_;
  direction input_;

public:
  input_base();
  ~input_base() = default;

  virtual direction getDirection();
  virtual void operator()() = 0;
  virtual void stop();
};

#endif //XBOX_CONTROLLER_INPUT_BASE_H
