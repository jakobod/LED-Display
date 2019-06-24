#include <iostream>
#include <output/Viewer.h>
#include <input/xbox_controller.h>

#include "game/SnakeGame.h"
#include "input/keyboard.h"
#include "snake/com/UDP_Client.h"

int main() {
  SnakeGame<xbox_controller, UDP_Client> game("192.168.178.28", "8888");
  std::thread t_game(std::ref(game));

  t_game.join(); // wait for game to be over
  std::cout << "game_over" << std::endl;

  return 0;
}
