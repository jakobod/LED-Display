//
// Created by boss on 6/18/19.
//

#ifndef XBOX_CONTROLLER_PRINTER_H
#define XBOX_CONTROLLER_PRINTER_H

#include <vector>
#include <map>
#include <opencv2/core/types.hpp>

class Printer {
  static const std::map<char, std::vector<cv::Point>> alphabet;
public:
  static const cv::Mat CLEAR_IMG;

  static void printChar(cv::Mat& mat, char c, cv::Point p, cv::Vec3b color);
  static void printString(cv::Mat& mat, std::string str, cv::Point p, cv::Vec3b color);
  static cv::Mat invert(cv::Mat& mat);
};


#endif //XBOX_CONTROLLER_PRINTER_H
