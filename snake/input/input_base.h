//
// Created by boss on 6/18/19.
//

#ifndef XBOX_CONTROLLER_INPUT_BASE_H
#define XBOX_CONTROLLER_INPUT_BASE_H

enum class input {
  up,
  down,
  left,
  right,
  start,
  select,
  A,
  B,
  X,
  Y,
  menu,
  none,
};

class input_base {
protected:
  bool running_;
  input input_;

public:
  input_base();
  ~input_base() = default;

  virtual input getInput();
  virtual void operator()() = 0;
  virtual void stop();
};

#endif //XBOX_CONTROLLER_INPUT_BASE_H
