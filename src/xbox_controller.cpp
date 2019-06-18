//
// Created by boss on 6/18/19.
//

#include "xbox_controller.h"
#include "gamepad.h"

xbox_controller::xbox_controller() {
  GamepadInit();
}

direction xbox_controller::getDirection() {
  GamepadUpdate();
  if (GamepadIsConnected(GAMEPAD_0)) {
    if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_UP))
      return up;
    else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_RIGHT))
      return right;
    else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_DOWN))
      return down;
    else if (GamepadButtonTriggered(GAMEPAD_0, BUTTON_DPAD_LEFT))
      return left;
  }
  return none;
}
