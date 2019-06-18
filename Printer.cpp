//
// Created by boss on 6/18/19.
//

#include <opencv2/core/mat.hpp>
#include "Printer.h"

void Printer::printChar(cv::Mat& mat, char c, cv::Point offset, cv::Vec3b color) {
  auto& points = alphabet.at(c);
  for (const auto& p : points)
    mat.at<cv::Vec3b>(p+offset) = color;
}

void Printer::printString(cv::Mat& mat, std::string str, cv::Point p, cv::Vec3b color) {
  for (const auto& c : str) {
    printChar(mat, c, p, color);
    p += cv::Point(4,0);
    if(c == 'm' || c == 'n' || c == 'w') {
      p += cv::Point(2,0);
    }
  }
}
