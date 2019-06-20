//
// Created by boss on 6/20/19.
//

#include <misc/Printer.h>
#include "game/gamestate/initial_state.h"

initial_state::initial_state() {

}

state_base* initial_state::action(input in, cv::Mat& mat) {
  return this;
}
