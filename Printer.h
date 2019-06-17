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


      {'g', {cv::Point(0,0), cv::Point(1,0), cv::Point(2,0), cv::Point(0,1), cv::Point(0,2),
             cv::Point(0,3), cv::Point(2,2), cv::Point(2,3), cv::Point(0,4), cv::Point(1,4),
             cv::Point(2,4),}},

        /*  // G
        cv::Point(1, 1), cv::Point(2, 1), cv::Point(3, 1), cv::Point(1, 2), cv::Point(1, 3),
            cv::Point(1, 4), cv::Point(1, 5), cv::Point(2, 5), cv::Point(3, 5), cv::Point(3, 4),
            cv::Point(3, 3),

            // A


            // M
            cv::Point(9, 1), cv::Point(9, 2), cv::Point(9, 3), cv::Point(9, 4), cv::Point(9, 5),
            cv::Point(10, 2), cv::Point(11, 3), cv::Point(12, 2), cv::Point(13, 1), cv::Point(13, 2),
            cv::Point(13, 3), cv::Point(13, 4), cv::Point(13, 5),

            // E
            cv::Point(15, 1), cv::Point(16, 1), cv::Point(17, 1), cv::Point(15, 2), cv::Point(15, 3),
            cv::Point(15, 4), cv::Point(15, 5), cv::Point(16, 3), cv::Point(16, 5), cv::Point(17, 5),

            // O
            cv::Point(1, 7), cv::Point(2, 7), cv::Point(3, 7), cv::Point(1, 8), cv::Point(1, 9),
            cv::Point(1, 10), cv::Point(1, 11), cv::Point(2, 11), cv::Point(3, 11), cv::Point(3, 10),
            cv::Point(3, 9), cv::Point(3, 8),
*/
  };

public:
  void print(cv::Mat& mat, char c, cv::Point p, cv::Vec3b color);
};


#endif //XBOX_CONTROLLER_PRINTER_H
