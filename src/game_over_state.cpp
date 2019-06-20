//
// Created by boss on 6/20/19.
//

#include <game/gamestate/running_state.h>
#include "game_over_state.h"

struct client_mock {
  void send(cv::Mat pic) {}
};

state_base* game_over_state::action(input in, cv::Mat& mat) {

  switch (in) {
    case input::start:
      return new running_state;

    case input::menu:
      return nullptr;

    default:
      break;
  }

  if (counter++ == 0) {
    client_mock c;
    Printer::gameOver(mat, c);
  }

  return this;
}

game_over_state::game_over_state() :
  counter(0)
{}
