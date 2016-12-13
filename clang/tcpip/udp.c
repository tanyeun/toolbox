#include <stdlib.h>

#include "udp.h"

/* 
 * error - wrapper for perror
 */
void error(char *msg) 
{
    perror(msg);
    exit(0);
}

int udp_init(connection_t *connection, in_addr_t addr, int port)
{
  if(connection){
    //Create socket
	//    AF_INET: IPv4
	//    SOCK_DGRAM : UDP
    connection->desc = socket(AF_INET , SOCK_DGRAM , 0);
    if (connection->desc == -1)
    {
        perror("Could not create socket");
		return -1;
	}
	/* setsockopt: Handy debugging trick that lets 
	 * us rerun the server immediately after we kill it; 
	 * otherwise we have to wait about 20 secs. 
	 * Eliminates "ERROR on binding: Address already in use" error. 
	 *   Parameters:
	 *     1) sockfd
	 *     2) level
	 *          SOL_SOCKET  : communication layer
	 *          IPPROTO_IP  : IP layer
	 *          IPPROTO_TCP : TCP layer
	 *     3) optname : name for the option
	 *     4) optval  : data structure used by this option
	 *     5) optlen  : size used by optval
	 */
	int optval = 1;
	setsockopt(connection->desc, SOL_SOCKET, SO_REUSEADDR, 
		(const void *)&optval , sizeof(int));

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

int udp_server_init(connection_t *connection, in_addr_t addr, int port)
{
  if ( udp_init(connection, addr, port) < 0 )
  {
    perror("ERROR on udp_init");
	return -1;
  }
  /* 
   * bind: associate the parent socket with a port 
   */
  if (bind(connection->desc , (struct sockaddr *)&(connection->addr) , 
              sizeof(connection->addr)) < 0)
  {
    perror("ERROR on binding");
	return -1;
  }
  return 1;
}

void msg_sendto(connection_t *conn, struct sockaddr_in dst_addr, char *buf)
{
    if ( conn == NULL )
	  error("conn is NULL");

    int len = sizeof(dst_addr);
	int n;

    n = sendto(conn->desc, buf, strlen(buf), 0, 
	       (struct sockaddr *) &dst_addr, len);
    if (n < 0) 
      error("ERROR in sendto");
}


int msg_recvfrom(connection_t *conn, struct sockaddr_in *src_addr, char *buf)
{
    if ( conn == NULL )
	  error("conn is NULL");
    if ( src_addr == NULL )
	  return -1;

    int nn;
    int len = sizeof(*src_addr);
    nn = recvfrom(conn->desc, buf, BUFSIZE, 0,
		 (struct sockaddr *) src_addr, (socklen_t*) &len);
    if (nn < 0)
      error("ERROR in recvfrom");

	return nn;
}
