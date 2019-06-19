//
// Created by boss on 6/18/19.
//

#include <chrono>
#include <thread>
#include "xbox_controller.h"
#include "gamepad.h"

xbox_controller::xbox_controller() : input_base() {
  GamepadInit();
}

void xbox_controller::operator()() {
  while (running_) {
    GamepadUpdate();
    if (GamepadIsConnected(GAMEPAD_0)) {
      if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_UP))
        input_ = up;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_RIGHT))
        input_ = right;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_DOWN))
        input_ = down;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_LEFT))
        input_ = left;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
