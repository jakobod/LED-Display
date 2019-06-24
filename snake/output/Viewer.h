//
// Created by boss on 6/21/19.
//

#ifndef SNAKE_GAME_VIEWER_H
#define SNAKE_GAME_VIEWER_H

#include <opencv2/highgui.hpp>
#include <thread>
#include <iostream>

template<class Transmitter>
class viewer {
  static viewer* instance_;
  Transmitter client_;
  static cv::Mat mat_;
  static std::thread t_viewer_;
  bool running_;

private:
  viewer(std::string& host, std::string& port) :
    client_(host, port),
    running_(true) {
    cv::namedWindow("snake", cv::WINDOW_NORMAL);
  }

  ~viewer() {
    instance_->stop();
  }

public:
  static viewer* instance(std::string host, std::string port) {
    if (!instance_) {
      instance_ = new viewer(host, port);
      t_viewer_ = std::thread(std::ref(*instance_));
    }
    return instance_;
  }

  static void trash() {
    delete instance_;
  }

  static void show(cv::Mat& mat) {
    std::cout << "new pic" << std::endl;
    mat_ = mat;
  }

  void operator()() {
    std::cout << "started viewer thread" << std::endl;
    while (running_) {
      std::cout << "showing something" << std::endl;
      client_.send(mat_);
      cv::imshow("snake", mat_);
      cv::waitKey(10);
    }
    std::cout << "ended viewer thread" << std::endl;
  }

  void stop() {
    std::cout << "stop called" << std::endl;
    running_ = false;
    t_viewer_.join();
  }
};

template<class Transmitter>
std::thread viewer<Transmitter>::t_viewer_;

template<class Transmitter>
viewer<Transmitter>* viewer<Transmitter>::instance_ = nullptr;

template<class Transmitter>
cv::Mat viewer<Transmitter>::mat_(cv::Size(23,13), CV_8UC3, cv::Scalar(0,0,0));

#endif //SNAKE_GAME_VIEWER_H
