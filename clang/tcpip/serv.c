#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h> //for threading , link with lpthread

#include "tcp.h"
 
void *connection_handler(void *);
 
int main(int argc , char *argv[])
{
  connection_t *conn;
  int new_socket = 0;
  int sock_len, *new_sock;
  struct sockaddr_in client;
	
  conn = malloc(sizeof(connection_t));
  tcp_server_init(conn, INADDR_ANY, 8888); 
	                      // listen to all interfaces
						            // available to this machine
     
  //Accept the incoming connection
  puts("Waiting for incoming connections...");
  sock_len = sizeof(struct sockaddr_in);
	char *message;
  while ( (new_socket = accept(conn->desc, (struct sockaddr *)&client, 
			      (socklen_t*)&sock_len)) ) 
	{
	  puts("Connection accepted");
	  //Reply to the client
	  message = "Hello Client , I have received your connection. "
		          "And now I will assign a handler for you\n";
	  write(new_socket , message , strlen(message));

	  pthread_t sniffer_thread;
	  new_sock = malloc(1);
	  *new_sock = new_socket;

	  if( pthread_create( &sniffer_thread , NULL ,  connection_handler , 
	                      (void*) new_sock) < 0)
	  {
		  perror("could not create thread");
		  return 1;
	  }

	  //Now join the thread , so that we dont terminate before the thread
	  //pthread_join( sniffer_thread , NULL);
	  puts("Handler assigned");
	}

  if (new_socket<0)
  {
    perror("accept failed");
	  return 1;
  }
 
  return 0;
}

/*
 * This will handle connection for each client
  * */
void *connection_handler(void *socket_desc)
{
  //Get the socket descriptor
  int sock = *(int*)socket_desc;
  int read_size;
  char message[256] , client_message[2000];

  //Send some messages to the client
  strcpy(message, "Greetings! I am your connection handler\n");
  write(sock , message , strlen(message));

  strcpy(message, "Now type something and i shall repeat what you type \n");
  write(sock , message , strlen(message));

  //Receive a message from client
  while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
  {
	  //Send the message back to client
    puts(client_message);
	  write(sock , client_message , strlen(client_message));
  }

  if(read_size == 0)
  {
	  puts("Client disconnected");
	  fflush(stdout);
  }
  else if(read_size == -1)
  {
	  perror("recv failed");
  }

  //Free the socket pointer
  free(socket_desc);
}
