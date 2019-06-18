//
// Created by boss on 6/16/19.
//

#include <string>
#include <iostream>
#include <cv.hpp>
#include "../snake/com/UDP_Client.h"

UDP_Client::UDP_Client(std::string host, std::string port) {
  if(!init(host, port)) {
    std::cerr << "init failed" << std::endl;
  }
}

bool UDP_Client::init(std::string& host, std::string port) {
  struct addrinfo hints;
  struct addrinfo* servinfo;
  int rv;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;

  if ((rv = getaddrinfo(host.c_str(), port.c_str(), &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return false;
  }

  // loop through all the results and make a socket
  for(p_ = servinfo; p_ != nullptr; p_ = p_->ai_next) {
    if ((sockfd_ = socket(p_->ai_family, p_->ai_socktype,
                         p_->ai_protocol)) == -1) {
      perror("talker: socket");
      continue;
    }

    break;
  }

  if (p_ == nullptr) {
    std::cerr << "talker: failed to create socket" << std::endl;
    return false;
  }

  return true;
}

void UDP_Client::send(cv::Mat mat) {
  size_t matSize = mat.total()*mat.elemSize();
  if (sendto(sockfd_, mat.data, matSize, 0, p_->ai_addr, p_->ai_addrlen) == -1) {
    perror("talker: sendto");
    return;
  }
}

UDP_Client::~UDP_Client() {
}
