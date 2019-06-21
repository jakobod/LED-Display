//
// Created by boss on 6/20/19.
//

#ifndef SNAKE_GAME_STATE_BASE_H
#define SNAKE_GAME_STATE_BASE_H

#include <input/input_base.h>
#include <opencv2/core/mat.hpp>

enum class state {
  initial = 0,
  running = 1,
  game_over = 2,
  end = 3,
};

template <class InputDevice, class Transmitter>
class state_base {
protected:
  InputDevice& input_;
  Transmitter& client_;

public:
  state_base(InputDevice& input, Transmitter& client) :
    input_(input),
    client_(client)
  {};
  virtual ~state_base() = default;

  virtual state action() = 0;
  virtual void reset() {};
};

#endif //SNAKE_GAME_STATE_BASE_H
