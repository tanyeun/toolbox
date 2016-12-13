#include "tcp.h"

int tcp_init(connection_t *connection, in_addr_t addr, int port)
{
  if(connection){
    //Create socket
	  //    AF_INET: IPv4
	  //    SOCK_STREAM : TCP ( UDP is SOCK_DGRAM )
    connection->desc = socket(AF_INET , SOCK_STREAM , 0);
    if (connection->desc == -1)
    {
        perror("Could not create socket");
		return -1;
    }

    //Prepare the sockaddr_in structure
    bzero(&(connection->addr),sizeof(connection->addr));
    connection->addr.sin_family = AF_INET;
    connection->addr.sin_addr.s_addr = addr;
    connection->addr.sin_port = htons(port); // 16 bit conversion
	                                         // y. htonl() for 32 bit
	printf("%s: complete\n", __FUNCTION__);
	return 1;
  }else
    return -1;
}

int tcp_client_init(connection_t *connection, in_addr_t addr, int port)
{
  if( tcp_init(connection, addr, port) < 0 )
    return -1;

  //Connect to remote server
  if (connect(connection->desc , (struct sockaddr *)&(connection->addr) , 
              sizeof(connection->addr)) < 0)
  {
      puts("connect error");
      return -1;
  }
   
  puts("TCP client Connected");
  return 1;
}

int tcp_server_init(connection_t *connection, in_addr_t addr, int port)
{
  if( tcp_init(connection, addr, port) < 0 )
    return -1;

  //Bind
  // connect the socket with the address info
  if (bind(connection->desc , (struct sockaddr *)&(connection->addr) , 
              sizeof(connection->addr)) < 0)
  {
      puts("bind error");
      return -1;
  }
     
  //Listen
  //  listen to the socket
  if( listen(connection->desc , 3) < 0 )
  {
    perror("listen error");
	return -1;
  }
   
  puts("TCP ServerConnected");
  return 1;
}
