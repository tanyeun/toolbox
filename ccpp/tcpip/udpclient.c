/* 
 * udpclient.c - A simple UDP client
 * usage: udpclient <host> <port>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h> 

#include "udp.h"

int main(int argc, char **argv) {
    int portno, n;

    struct hostent *server;
    char *hostname;
	in_addr_t serv_addr; 
	connection_t *conn;
    int serverlen;

    char buf[BUFSIZE];

    /* check command line arguments */
    if (argc != 3) {
       fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
       exit(0);
    }
    hostname = argv[1];
    portno = atoi(argv[2]);

    /* gethostbyname: get the server's DNS entry */
    /* build the server's Internet address */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }
    bcopy((char *)server->h_addr, 
	  (char *)&serv_addr, server->h_length);

    conn = malloc(sizeof(connection_t));
    udp_init(conn, serv_addr, portno);

    /* get a message from the user */
    bzero(buf, BUFSIZE);
    printf("Please enter msg: ");
    fgets(buf, BUFSIZE, stdin);

    // server address : conn->addr
    msg_sendto(conn, conn->addr, buf);
    
    /* print the server's reply */
	msg_recvfrom(conn, &(conn->addr), buf);
    printf("Echo from server: %s", buf);
    return 0;
}
