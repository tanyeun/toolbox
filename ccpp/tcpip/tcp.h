#ifndef TCP_H
#define TCP_H

#include <stdio.h>
#include <string.h>
#include "ip.h"

int tcp_init(connection_t *connection, in_addr_t addr, int port);
int tcp_client_init(connection_t *connection, in_addr_t addr, int port);
int tcp_server_init(connection_t *connection, in_addr_t addr, int port);

#endif //TCP_H 
