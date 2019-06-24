//
// Created by boss on 6/18/19.
//

#ifndef XBOX_CONTROLLER_SNAKEGAME_H
#define XBOX_CONTROLLER_SNAKEGAME_H

#include <thread>
#include "input/input_base.h"
#include <random>
#include <game/gamestate/state_base.h>
#include <game/gamestate/running_state.h>
#include <game/gamestate/initial_state.h>
#include <iostream>
#include <output/Viewer.h>

template<class InputDevice, class Transmitter>
class SnakeGame {
  InputDevice input_;
  std::thread t_input_;
  viewer<Transmitter>* viewer_;
  std::vector<state_base<InputDevice>*> states_;
  state state_;
  bool running_;

public:
  SnakeGame(std::string host, std::string port) :
    input_(),
    t_input_(std::ref(input_)),
    viewer_(viewer<Transmitter>::instance(std::move(host), std::move(port))),
    states_{
      new initial_state<InputDevice, Transmitter>(input_),
      new running_state<InputDevice, Transmitter>(input_),
      new game_over_state<InputDevice, Transmitter>(input_),
    },
    state_(state::initial),
    running_(true)
  {}

  ~SnakeGame() {
    viewer<Transmitter>::trash();
    input_.stop();
    t_input_.join();
  };

  void  operator()() {
    while (running_) {
      state_ = states_[static_cast<int>(state_)]->action();
      if(state_ == state::end) running_ = false;
      states_[static_cast<int>(state_)]->reset();
    }
    std::cout << "THE END!" << std::endl;
  }
};



#endif //XBOX_CONTROLLER_SNAKEGAME_H
