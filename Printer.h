//
// Created by boss on 6/18/19.
//

#ifndef XBOX_CONTROLLER_PRINTER_H
#define XBOX_CONTROLLER_PRINTER_H

#include <vector>
#include <map>
#include <opencv2/core/types.hpp>

class Printer {
  const std::map<char, std::vector<cv::Point>> alphabet = {
      {'a', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(1,0), cv::Point(2,1),
             cv::Point(2,0), cv::Point(2,2), cv::Point(0,3), cv::Point(1,2), cv::Point(2,3),
             cv::Point(0,4), cv::Point(2,4)}},

      {'b', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(1,0), cv::Point(2,1),
             cv::Point(2,0), cv::Point(2,2), cv::Point(0,3), cv::Point(1,2), cv::Point(2,3),
             cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},

      {'c', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(1,0), cv::Point(2,0),
             cv::Point(0,3), cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},

      {'d', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(1,0), cv::Point(2,1),
             cv::Point(0,3), cv::Point(2,2), cv::Point(2,3), cv::Point(0,4), cv::Point(1,4)}},


      {'e', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,0), cv::Point(0,1), cv::Point(0,2),
             cv::Point(1,2), cv::Point(0, 3), cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},

      {'f', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,0), cv::Point(0,1), cv::Point(0,2),
             cv::Point(1,2), cv::Point(0, 3), cv::Point(0,4)}},

      {'g', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,0), cv::Point(0,1), cv::Point(0,2),
             cv::Point(0,3), cv::Point(2,2), cv::Point(2,3), cv::Point(0,4), cv::Point(1,4),
             cv::Point(2,4)}},

      {'h', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(2,1), cv::Point(2,0),
             cv::Point(2,2), cv::Point(0,3), cv::Point(1,2), cv::Point(2,3), cv::Point(0,4),
             cv::Point(2,4)}},

      {'i', {cv::Point(1,0), cv::Point(1,1), cv::Point(1,2), cv::Point(1,3), cv::Point(1,4)}},

      {'j', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,1),
             cv::Point(2,0), cv::Point(2,2), cv::Point(0,3), cv::Point(2,3),
             cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},

      {'k', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(2,1), cv::Point(2,0),
             cv::Point(0,3), cv::Point(1,2), cv::Point(2,3), cv::Point(0,4),
             cv::Point(2,4)}},

      {'l', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2),
             cv::Point(0, 3), cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},

      {'m', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(0,3), cv::Point(0,4),
             cv::Point(1,1), cv::Point(2,2), cv::Point(3,1), cv::Point(4,0), cv::Point(4,1),
             cv::Point(4,2), cv::Point(4,3), cv::Point(4,4)}},

      {'n', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(0,3), cv::Point(0,4),
             cv::Point(1,1), cv::Point(2,2), cv::Point(3,3), cv::Point(4,4), cv::Point(4,1),
             cv::Point(4,2), cv::Point(4,3), cv::Point(4,0)}},

      {'o', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(1,0), cv::Point(2,1),
             cv::Point(2,0), cv::Point(2,2), cv::Point(0,3), cv::Point(2,3),
             cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},

      {'p', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,0), cv::Point(2,1), cv::Point(2,2), cv::Point(0,1), cv::Point(0,2),
             cv::Point(1,2), cv::Point(0,3), cv::Point(0,4)}},

      {'q', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,0), cv::Point(2,1), cv::Point(2,2), cv::Point(0,1), cv::Point(0,2),
             cv::Point(1,2), cv::Point(2,3), cv::Point(2,4)}},

      {'r', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(2,1), cv::Point(1,0), cv::Point(2,0),
             cv::Point(0,3), cv::Point(1,2), cv::Point(2,3), cv::Point(0,4),
             cv::Point(2,4)}},

      {'s', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(1,0),
             cv::Point(2,0), cv::Point(2,2), cv::Point(1,2), cv::Point(2,3),
             cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},

      {'t', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,0), cv::Point(1,1), cv::Point(1,2), cv::Point(1,3), cv::Point(1,4)}},

      {'u', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(2,1),
             cv::Point(2,0), cv::Point(2,2), cv::Point(0,3), cv::Point(2,3),
             cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},

      {'v', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(2,1),
             cv::Point(2,0), cv::Point(2,2), cv::Point(0,3), cv::Point(2,3),
             cv::Point(1,4)}},

      {'w', {cv::Point(0,0), cv::Point(0,1), cv::Point(0,2), cv::Point(0,3), cv::Point(0,4),
             cv::Point(1,3), cv::Point(2,2), cv::Point(3,3), cv::Point(4,0), cv::Point(4,1),
             cv::Point(4,2), cv::Point(4,3), cv::Point(4,4)}},

      {'x', {cv::Point(0,0), cv::Point(0,1), cv::Point(2,1), cv::Point(2,0),
             cv::Point(0,3), cv::Point(1,2), cv::Point(2,3), cv::Point(0,4),
             cv::Point(2,4)}},

      {'y', {cv::Point(0,0), cv::Point(0,1), cv::Point(2,0), cv::Point(2,1), cv::Point(1,2), cv::Point(1,3), cv::Point(1,4)}},

      {'z', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,1),
             cv::Point(2,0), cv::Point(0,3), cv::Point(1,2),
             cv::Point(0,4), cv::Point(1,4), cv::Point(2,4)}},
  };

public:
  void printChar(cv::Mat& mat, char c, cv::Point p, cv::Vec3b color);
  void printString(cv::Mat& mat, std::string str, cv::Point p, cv::Vec3b color);
};


#endif //XBOX_CONTROLLER_PRINTER_H
