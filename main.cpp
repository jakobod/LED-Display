#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>
#include <thread>
#include <random>
#include <input/xbox_controller.h>
#include <misc/Color.h>
#include <game/SnakeGame.h>
#include <input/keyboard.h>

#include "snake/com/UDP_Client.h"
#include "snake/game/Snake.h"
#include "snake/game/Gem.h"
#include "snake/misc/Printer.h"


void show(cv::Mat& pic, UDP_Client& client, int duration = 0) {
  cv::imshow("de", pic);
  client.send(Printer::invert(pic));
  cv::waitKey(duration);
}

void weirdPattern(cv::Mat& pane, UDP_Client& client) {
  int count = 0;
  for (int y = 0; y < pane.rows; ++y) {
    for (int x = 0; x < pane.cols; ++x) {
      auto countMod = count%3;
      if (countMod == 0)
        pane.at<cv::Vec3b>(y, x) = Color::RED;
      else if (countMod == 1)
        pane.at<cv::Vec3b>(y, x) = Color::GREEN;
      if (countMod == 2)
        pane.at<cv::Vec3b>(y, x) = Color::BLUE;
      ++count;
      show(pane, client, 25);
    }
  }
  show(pane, client, 1000);
}

void placeGem(cv::Mat& mat, cv::Point pos) {
  mat.at<cv::Vec3b>(pos) = Color::YELLOW;
}

int main() {
  cv::namedWindow("de", cv::WINDOW_NORMAL);
  SnakeGame<keyboard, UDP_Client> game("192.168.178.28", "8888");

  bool running = true;
  while (running) {
    if (!game.loop()) {
      running = false;
    }
  }
  std::cout << "game_over" << std::endl;
  return 0;
}
