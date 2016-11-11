#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#include "config.h"
#include "common.h"

int main()
{
    int msqid;

	// create queue and make it read and appendable by all
    int msgflg = IPC_CREAT | 0666;

    key_t server_key = 1234; // define server_key
    message_buf buf;
    size_t buf_length;

    sbuf.mtype = 1;
    (void) strcpy(sbuf.mtext, "Did you get this?");
    buf_length = strlen(buf.mtext) + 1 ;

    /*
     * Send a message.
     */
    if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
       printf ("%d, %ld, %s, %zu\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
       perror("msgsnd");
       exit(1);
    }
   else 
      printf("Message: \"%s\" Sent\n", sbuf.mtext);
      
    exit(0);
}
