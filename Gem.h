//
// Created by boss on 6/17/19.
//

#ifndef XBOX_CONTROLLER_GEM_H
#define XBOX_CONTROLLER_GEM_H


#include <opencv2/core/types.hpp>

class Gem {
  cv::Point pos_;
  bool isPresent;

public:
  Gem(cv::Point pos);
  ~Gem() = default;

  void consume();
  explicit operator bool() const;
  void printTo(cv::Mat& mat, cv::Vec3b color);

  friend bool operator==(const Gem& gem, const cv::Point& point) {
    return gem.pos_ == point;
  }
};


#endif //XBOX_CONTROLLER_GEM_H
