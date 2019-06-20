#include <iostream>

#include "game/SnakeGame.h"
#include "input/keyboard.h"
#include "snake/com/UDP_Client.h"

int main() {
  SnakeGame<keyboard, UDP_Client> game("192.168.178.28", "8888");

  bool running = true;
  while (running) {
    running = game.loop();
  }

  std::cout << "game_over" << std::endl;
  return 0;
}
