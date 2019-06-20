//
// Created by boss on 6/20/19.
//

#include "running_state.h"

running_state::running_state() :
  gem_(cv::Point(0,0)),
  snake_({cv::Point(13,5)}, cv::Size(23,13)),
  dir_(1,0),
  dev_(),
  rng_(dev_()),
  dist12_(0,12),
  dist22_(0,22)
{}
