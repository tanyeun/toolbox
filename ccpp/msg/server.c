#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"

int main()
{
    int msqid;
    key_t server_key;
    message_buf  buf;

	// create a queue and make it read and appendable by all
    int msgflg = IPC_CREAT | 0666;

    server_key = 1234;

    if ((msqid = msgget(server_key, msgflg)) < 0) {
        perror("msgget");
        exit(1);
    }

   while( 1 ) {   
    /*
     * Receive an answer of message type 1.
     */
    if (msgrcv(msqid, &buf, MSGSZ, 1, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }

    /*
     * Print the answer.
     */
    printf("%s\n", buf.mtext);
  }
}
