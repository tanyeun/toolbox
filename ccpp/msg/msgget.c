/*
 * msgget.c: Illustrate the msgget() function.
 * This is a simple exerciser of the msgget() function. It prompts
 * for the arguments, makes the call, and reports the results.
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
  key_t  key;  /* key to be passed to msgget() */
  int  msgflg,  /* msgflg to be passed to msgget() */
   msqid;  /* return value from msgget() */
 
  (void) fprintf(stderr,"All numeric input is expected to follow C conventions:\n");
  (void) fprintf(stderr,"\t0x... is interpreted as hexadecimal,\n");
  (void) fprintf(stderr, "\t0... is interpreted as octal,\n");
  (void) fprintf(stderr, "\totherwise, decimal.\n");
  (void) fprintf(stderr, "IPC_PRIVATE == %#x\n", IPC_PRIVATE);
  (void) fprintf(stderr, "Enter key: ");
  (void) scanf("%i", &key);

  (void) fprintf(stderr, "\nExpected flags for msgflg argument are:\n");
  (void) fprintf(stderr, "\tIPC_EXCL =\t%#8.8o\n", IPC_EXCL);
  (void) fprintf(stderr, "\tIPC_CREAT =\t%#8.8o\n", IPC_CREAT);
  (void) fprintf(stderr, "\towner read =\t%#8.8o\n", 0400);
  (void) fprintf(stderr, "\towner write =\t%#8.8o\n", 0200);
  (void) fprintf(stderr, "\tgroup read =\t%#8.8o\n", 040);
  (void) fprintf(stderr, "\tgroup write =\t%#8.8o\n", 020);
  (void) fprintf(stderr, "\tother read =\t%#8.8o\n", 04);
  (void) fprintf(stderr, "\tother write =\t%#8.8o\n", 02);
  (void) fprintf(stderr, "Enter msgflg value: ");
  (void) scanf("%i", &msgflg);
 
  (void) fprintf(stderr, "\nmsgget: Calling msgget(%#x,%#o)\n",
                 key, msgflg);
  if ((msqid = msgget(key, msgflg)) == -1)
  {
   perror("msgget: msgget failed");
   exit(1);
  } else {
   (void) fprintf(stderr,
    "msgget: msgget succeeded: msqid = %d\n", msqid);
   exit(0);
  }
}
