#include <iostream>

#include "game/SnakeGame.h"
#include "input/keyboard.h"
#include "snake/com/UDP_Client.h"

struct client_mock {
  void send(cv::Mat pic) {}
};

int main() {
  client_mock cl;
  cv::namedWindow("gamePane", cv::WINDOW_NORMAL);
  Printer::shiftText("hello world", cl);

  SnakeGame<keyboard, UDP_Client> game("192.168.178.28", "8888");
  std::thread t_game(std::ref(game));


  t_game.join(); // wait for game to be over
  std::cout << "game_over" << std::endl;
  return 0;
}
