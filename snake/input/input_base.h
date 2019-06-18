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
  virtual direction getDirection() = 0;
};

#endif //XBOX_CONTROLLER_INPUT_BASE_H
