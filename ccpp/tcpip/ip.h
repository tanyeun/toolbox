#ifndef IP_H
#define IP_H

#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h> //inet_addr 

#define BUFSIZE 1024

typedef struct{
  int desc;
  struct sockaddr_in addr;
}connection_t;

#endif //IP_H
