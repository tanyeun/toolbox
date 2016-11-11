#ifndef UDP_H
#define UDP_H
#include <stdio.h>
#include <string.h>

#include "ip.h"

void error(char *msg);
int udp_init(connection_t *connection, in_addr_t addr, int port);
int udp_server_init(connection_t *connection, in_addr_t addr, int port);
void msg_sendto(connection_t *conn, struct sockaddr_in dst_addr, char *buf);
int msg_recvfrom(connection_t *conn, struct sockaddr_in *src_addr, char *buf);

#endif //UDP_H 
