#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#include "config.h"
#include "common.h"

int main(int argc, char** argv)
{
    if ( argc < 2 )
	  return -1;
	
    int msqid;

	  // create queue and make it read and appendable by all
    int msgflg = IPC_CREAT | 0666;

    key_t server_key = 1234; // define server_key
    message_buf buf;
    size_t buf_length;

    msqid = register_key(server_key, msgflg);

    buf.mtype = 1;
    (void) strcpy(buf.mtext, argv[1]);
    buf_length = strlen(buf.mtext) + 1 ;

    /*
     * Send a message.
     */
    if (msgsnd(msqid, &buf, buf_length, IPC_NOWAIT) < 0) {
       printf ("%d, %ld, %s, %zu\n", msqid, buf.mtype, buf.mtext, buf_length);
       perror("msgsnd");
       exit(1);
    }else 
      printf("Message: \"%s\" Sent\n", buf.mtext);
      
    exit(0);
}
