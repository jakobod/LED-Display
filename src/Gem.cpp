//
// Created by boss on 6/17/19.
//

#include <opencv2/core/mat.hpp>
#include "../snake/game/Gem.h"

Gem::Gem() :
  dev_(),
  rng_(dev_()),
  dist12_(0,12),
  dist22_(0,22),
  pos_{cv::Point(dist22_(rng_), dist12_(rng_))},
  isPresent{false} {}

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

void Gem::reset() {
  pos_ = cv::Point(dist22_(rng_), dist12_(rng_));
  isPresent = true;
}



