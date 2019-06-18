//
// Created by boss on 6/16/19.
//

#ifndef MATCHING_UDP_CLIENT_H
#define MATCHING_UDP_CLIENT_H

#include <opencv2/core/mat.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class UDP_Client {
public:
  UDP_Client(std::string host, std::string port);
  ~UDP_Client();

  bool init(std::string& host, std::string port);
  void send(cv::Mat mat);
private:
  int sockfd_;
  addrinfo* p_;
};


#endif //MATCHING_UDP_CLIENT_H
