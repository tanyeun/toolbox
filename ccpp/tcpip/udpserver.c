/* 
 * udpserver.c - A simple UDP echo server 
 * usage: udpserver <port>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <netinet/in.h>

#include "udp.h"

int main(int argc, char **argv) {
  int portno; /* port to listen on */

  connection_t *server;

  int clientlen; /* byte size of client's address */
  struct sockaddr_in clientaddr; /* client addr */

  struct hostent *hostp; /* client host info */
  char buf[BUFSIZE]; /* message buf */
  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */
  int nn; /* message byte size */

  /* 
   * check command line arguments 
   */
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);

  server = malloc(sizeof(connection_t));
  udp_server_init(server, htonl(INADDR_ANY), portno); 


  /* 
   * main loop: wait for a datagram, then echo it
   */
  clientlen = sizeof(clientaddr);
  while (1) {

    /*
     * receive a UDP datagram from a client
     */
    bzero(buf, BUFSIZE);
	nn = msg_recvfrom(server, &clientaddr, buf);

    /* 
     * gethostbyaddr: determine who sent the datagram
     */
    hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
			  sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      error("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      error("ERROR on inet_ntoa\n");

    printf("server received datagram from %s (%s)\n", 
	        hostp->h_name, hostaddrp);
    printf("server received %lu/%d bytes: %s\n", strlen(buf), nn, buf);
    
    /* 
     * echo the input back to the client 
     */
	msg_sendto(server, clientaddr, buf);
  }
}
