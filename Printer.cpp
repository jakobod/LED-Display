//
// Created by boss on 6/18/19.
//

#include <opencv2/core/mat.hpp>
#include "Printer.h"

void Printer::print(cv::Mat& mat, char c, cv::Point offset, cv::Vec3b color) {
  auto& points = alphabet.at(c);
  for (const auto& p : points)
    mat.at<cv::Vec3b>(p+offset) = color;
}
