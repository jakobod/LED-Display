//
// Created by boss on 6/17/19.
//

#ifndef XBOX_CONTROLLER_GEM_H
#define XBOX_CONTROLLER_GEM_H


#include <opencv2/core/types.hpp>
#include <random>

class Gem {
  std::random_device dev_;
  std::mt19937 rng_;
  std::uniform_int_distribution<std::mt19937::result_type> dist12_;
  std::uniform_int_distribution<std::mt19937::result_type> dist22_;
  cv::Point pos_;
  bool isPresent;

public:
  Gem();
  ~Gem() = default;

  void consume();
  explicit operator bool() const;
  void printTo(cv::Mat& mat, cv::Vec3b color);
  void reset();

  friend bool operator==(const Gem& gem, const cv::Point& point) {
    return gem.pos_ == point;
  }
};


#endif //XBOX_CONTROLLER_GEM_H
