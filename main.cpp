#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>
#include <thread>
#include <random>

#include "gamepad.h"
#include "UDP_Client.h"
#include "Snake.h"
#include "Gem.h"
#include "Printer.h"

static const cv::Mat CLEAR_IMG(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));

static const cv::Vec3b BLACK(0,0,0);
static const cv::Vec3b RED(0,0,255);
static const cv::Vec3b GREEN(0,255,0);
static const cv::Vec3b BLUE(255,0,0);
static const cv::Vec3b YELLOW(0,255,255);



enum Button {
  up = 0,
  down = 1,
  left = 2,
  right = 3,
  start = 4,
  none = 5
};

cv::Mat invert(cv::Mat& mat) {
  cv::Mat inv(mat.size(), mat.type());

  for (int y = 0; y < mat.rows; ++y) {
    if ((y % 2) == 0) {
      for (int x = 0; x < mat.cols; ++x) {
        inv.at<cv::Vec3b>(y, x) = mat.at<cv::Vec3b>(y, x);
      }
    } else {
      for (int x = 0; x < mat.cols; ++x) {
        inv.at<cv::Vec3b>(y, x) = mat.at<cv::Vec3b>(y, mat.cols-x-1);
      }
    }
  }
  return inv;
}

void show(cv::Mat& pic, UDP_Client& client, int duration = 0) {
  cv::imshow("de", pic);
  client.send(invert(pic));
  cv::waitKey(duration);
}

void weirdPattern(cv::Mat& pane, UDP_Client& client) {
  int count = 0;
  for (int y = 0; y < pane.rows; ++y) {
    for (int x = 0; x < pane.cols; ++x) {
      auto countMod = count%3;
      if (countMod == 0)
        pane.at<cv::Vec3b>(y, x) = RED;
      else if (countMod == 1)
        pane.at<cv::Vec3b>(y, x) = GREEN;
      if (countMod == 2)
        pane.at<cv::Vec3b>(y, x) = BLUE;
      ++count;
      show(pane, client, 25);
    }
  }
  show(pane, client, 1000);
}

Button direction(GAMEPAD_DEVICE dev) {
  if (GamepadIsConnected(dev)) {
    if (GamepadButtonTriggered(dev, BUTTON_DPAD_UP))
      return up;
    else if (GamepadButtonTriggered(dev, BUTTON_DPAD_RIGHT))
      return right;
    else if (GamepadButtonTriggered(dev, BUTTON_DPAD_DOWN))
      return down;
    else if (GamepadButtonTriggered(dev, BUTTON_DPAD_LEFT))
      return left;
    else if (GamepadButtonTriggered(dev, BUTTON_START))
      return start;
  }
  return none;
}

void placeGem(cv::Mat& mat, cv::Point pos) {
  mat.at<cv::Vec3b>(pos) = YELLOW;
}

void gameOver(cv::Mat& mat, UDP_Client& client, Printer printer) {
  weirdPattern(mat, client);
  mat = cv::Mat(mat.size(), mat.type(), cv::Scalar(0,0,0));
  printer.printString(mat, "game", cv::Point(1,1), RED);
  printer.printString(mat, "over", cv::Point(2,7), RED);
  show(mat, client);
}

int main() {
  GamepadInit();
  UDP_Client client("192.168.178.28", "8888");
  Printer printer;
  cv::namedWindow("de", cv::WINDOW_NORMAL);
  Snake snake({cv::Point(13,5)}, cv::Size(23,13));
  cv::Point dir(1,0);

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist22(0,22);
  std::uniform_int_distribution<int> dist12(0,12);

  Gem gem(cv::Point(dist22(rng), dist12(rng)));

  bool running = true;
  while (running) {
    if (!gem)
      gem = Gem(cv::Point(dist22(rng), dist12(rng)));
    GamepadUpdate();
    switch (direction(GAMEPAD_0)) {
      case up:
        dir = cv::Point(0, -1);
        break;

      case down:
        dir = cv::Point(0, 1);
        break;

      case left:
        dir = cv::Point(-1, 0);
        break;

      case right:
        dir = cv::Point(1, 0);
        break;

      case start:
        dir = cv::Point(1,0);
        snake = Snake({cv::Point(13,5)}, cv::Size(23,13));
        break;

      default:
        break;
    }

    cv::Mat pane(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));
    if(!snake.step(dir, gem)) {
      running = false;
    }
    gem.printTo(pane, YELLOW);
    snake.printTo(pane, RED);

    cv::imshow("de", pane);
    client.send(invert(pane));
    cv::waitKey(500);
  }

  cv::Mat pane(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));
  gameOver(pane, client, printer);
  return 0;
}
