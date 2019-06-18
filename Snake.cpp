//
// Created by boss on 6/17/19.
//

#include <opencv2/core/mat.hpp>
#include <algorithm>
#include "Snake.h"

Snake::Snake(std::vector<cv::Point> points, cv::Size size) :
  points_{std::move(points)},
  size_{std::move(size)}{}

bool Snake::step(cv::Point dir, Gem& gem) {
  auto tmp = points_[points_.size()-1] + dir;
  if (tmp.x >= size_.width) {
    tmp.x -= size_.width;
  } else if (tmp.x < 0) {
    tmp.x = size_.width-1;
  }
  if (tmp.y >= size_.height) {
    tmp.y -= size_.height;
  } else if (tmp.y < 0) {
    tmp.y = size_.height-1;
  }

  auto it = std::find(points_.begin(), points_.end(), tmp);
  if (it != points_.end() && it != points_.end()-1) {
    return false;
  }

  if(gem == points_[points_.size()-1]) {
    points_.push_back(tmp);
    gem.consume();
  } else {
    // shift all values
    for (int i = 0; i < points_.size() - 1; ++i) {
      points_[i] = points_[i + 1];
    }
    points_[points_.size() - 1] = tmp;
  }
  return true;
}

void Snake::printTo(cv::Mat& pic, cv::Vec3b color) {
  for (const auto& p : points_) {
    pic.at<cv::Vec3b>(p) = color;
  }
}
