#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tcp.h"
 
int main(int argc , char *argv[])
{
    connection_t *conn;
	char *message, server_reply[2000];

    conn = malloc(sizeof(connection_t));
	tcp_client_init(conn, inet_addr("127.0.0.1"), 8888);

    message = "GET / HTTP/1.1\r\n\r\n";
	if( send(conn->desc , message , strlen(message) , 0) < 0)
	{
	  puts("Send failed");
	  return 1;
	}
	puts("Data Send\n");

	//Receive a reply from the server
	if( recv(conn->desc, server_reply , 2000 , 0) < 0)
	{
	  puts("recv failed");
	}
	puts("Reply received\n");
	puts(server_reply);
									     
	close(conn->desc);
    return 0;
}
