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
        input_ = input::up;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_RIGHT))
        input_ = input::right;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_DOWN))
        input_ = input::down;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_LEFT))
        input_ = input::left;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_A))
        input_ = input::A;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_B))
        input_ = input::B;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_X))
        input_ = input::X;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_Y))
        input_ = input::Y;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_START))
        input_ = input::start;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_BACK))
        input_ = input::select;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_COUNT))
        input_ = input::menu;
      else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_A))
        input_ = input::A;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
