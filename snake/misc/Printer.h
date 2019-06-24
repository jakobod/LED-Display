//
// Created by boss on 6/18/19.
//

#ifndef XBOX_CONTROLLER_PRINTER_H
#define XBOX_CONTROLLER_PRINTER_H

#include <vector>
#include <map>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <misc/Color.h>
#include <output/Viewer.h>

class Printer {
  static const std::map<char, std::vector<cv::Point>> alphabet;
public:
  static const cv::Mat CLEAR_IMG;

  static void printChar(cv::Mat& mat, char c, cv::Point p, cv::Vec3b color);
  static void printString(cv::Mat& mat, std::string str, cv::Point p, cv::Vec3b color);


  static cv::Mat invert(cv::Mat& mat);

  template <class Transmitter>
  static void weirdPattern(cv::Mat& pane) {
    int count = 0;
    for (int y = 0; y < pane.rows; ++y) {
      for (int x = 0; x < pane.cols; ++x) {
        auto countMod = count%3;
        if (countMod == 0)
          pane.at<cv::Vec3b>(y, x) = Color::RED;
        else if (countMod == 1)
          pane.at<cv::Vec3b>(y, x) = Color::GREEN;
        if (countMod == 2)
          pane.at<cv::Vec3b>(y, x) = Color::BLUE;
        ++count;
        show<Transmitter>(pane, 5);
      }
    }
    show<Transmitter>(pane, 1000);
  }

  template <class Transmitter>
  static void shiftText(std::string str) {
    for (int i = 0; i < 23+(str.size()*4); ++i) {
      cv::Mat mat(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));
      printString(mat, str, cv::Point(22-i, 5), Color::BLUE);
      show<Transmitter>(mat, 500);
    }
  }


  template<class Transmitter>
  static void gameOver(cv::Mat& mat) {
    weirdPattern<Transmitter>(mat);
    mat = cv::Mat(mat.size(), mat.type(), cv::Scalar(0,0,0));
    Printer::printString(mat, "game", cv::Point(3,1), Color::RED);
    Printer::printString(mat, "over", cv::Point(4,7), Color::RED);
    show<Transmitter>(mat);
  }

  template <class Transmitter>
  static void show(cv::Mat& pic, int duration = 0) {
    viewer<Transmitter>::show(pic);
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
  }
};


#endif //XBOX_CONTROLLER_PRINTER_H
