//
// Created by boss on 6/17/19.
//

#include <opencv2/core/mat.hpp>
#include "Gem.h"

Gem::Gem(cv::Point pos) :
  pos_{pos},
  isPresent{true} {}

void Gem::consume() {
  isPresent = false;
}

Gem::operator bool() const {
  return isPresent;
}

void Gem::printTo(cv::Mat& mat, cv::Vec3b color) {
  if (isPresent)
    mat.at<cv::Vec3b>(pos_) = color;
  else
    mat.at<cv::Vec3b>(pos_) = cv::Vec3b(0,0,0);
}



