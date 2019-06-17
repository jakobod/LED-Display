//
// Created by boss on 6/17/19.
//

#ifndef XBOX_CONTROLLER_SNAKE_H
#define XBOX_CONTROLLER_SNAKE_H


#include <queue>
#include <opencv2/core/mat.hpp>
#include "Gem.h"

class Snake {
  std::vector<cv::Point> points_;
  cv::Size size_;

public:
  Snake(std::vector<cv::Point> points, cv::Size size);
  ~Snake() = default;

  void step(cv::Point dir, Gem& gem);
  void printTo(cv::Mat& mat, cv::Vec3b color);

};


#endif //XBOX_CONTROLLER_SNAKE_H
