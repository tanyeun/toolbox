/*
 * msgop.c: Illustrate the msgsnd() and msgrcv() functions.
 *
 * This is a simple exerciser of the message send and receive
 * routines. It allows the user to attempt to send and receive as many
 * messages as wanted to or from one message queue.
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "config.h"

static int ask();

char first_on_queue[] = "-> first message on queue",
     full_buf[] = "Message buffer overflow. Extra message text discarded.";

int main()
{
  register int    c;        /* message text input */
  int             choice;   /* user's selected operation code */
  register int    i;        /* loop control for mtext */
  int             msgflg;   /* message flags for the operation */
  struct msgbuf*  msgp;     /* pointer to the message buffer */
  int             msgsz;    /* message size */
  long            msgtyp;   /* desired message type */
  int             msqid,    /* message queue ID to be used */
                  maxmsgsz, /* size of allocated message buffer */
                  rtrn;     /* return value from msgrcv or msgsnd */
  (void) fprintf(stderr,  "All numeric input is expected to follow C conventions:\n");
  (void) fprintf(stderr,  "\t0x... is interpreted as hexadecimal,\n");
  (void) fprintf(stderr, "\t0... is interpreted as octal,\n");
  (void) fprintf(stderr, "\totherwise, decimal.\n");
  /* Get the message queue ID and set up the message buffer. */
  (void) fprintf(stderr, "Enter msqid: ");
  (void) scanf("%i", &msqid);
  /*
   * Note that <sys/msg.h> includes a definition of struct msgbuf
   * with the mtext field defined as:
   *   char mtext[1];
   * therefore, this definition is only a template, not astructure
   * definition that you can use directly, unless you want only to
   * send and receive messages of 0 or 1 byte. To handle this,
   * malloc an area big enough to contain the template - the size
   * of the mtext template field + the size of the mtext field
   * wanted. Then you can use the pointer returned by malloc as a
   * struct msgbuf with an mtext field of the size you want. Note
   * also that sizeof msgp->mtext is valid even though msgp isn't
   * pointing to anything yet. Sizeof doesn't dereference msgp,but
   * uses its type to figure out what you are asking about.
   */
  (void) fprintf(stderr,  "Enter the message buffer size you want:");
  (void) scanf("%i", &maxmsgsz);

  if (maxmsgsz < 0) {
    (void) fprintf(stderr, "msgop: %s\n", "The message buffer size must be >= 0.");
    exit(1);
  }
  msgp = (struct msgbuf *)malloc((unsigned)(sizeof(struct msgbuf)
                                          - sizeof msgp->mtext + maxmsgsz));
  if (msgp == NULL) {
   (void) fprintf(stderr, "msgop: %s %d byte messages.\n",
     "could not allocate message buffer for", maxmsgsz);
   exit(1);
  }
  /* Loop through message operations until the user is ready to quit. */
  while ( ( choice = ask()) ) {
   switch (choice) 
   {
     case 1: /* msgsnd() requested: Get the arguments, make the
                call, and report the results. */
      (void) fprintf(stderr, "Valid msgsnd message %s\n",
                             "types are positive integers.");
      (void) fprintf(stderr, "Enter msgp->mtype: ");
      (void) scanf("%li", &msgp->mtype);

      if (maxmsgsz) {
       /* Since you've been using scanf, you need the loop
          below to throw away the rest of the input on the
          line after the entered mtype before you start
          reading the mtext. */
       while ((c = getchar()) != '\n' && c != EOF)
	     ;
         (void) fprintf(stderr, "Enter a %s:\n",
                                "one line message");

       for (i = 0; ((c = getchar()) != '\n'); i++) {
         if (i >= maxmsgsz) {
           (void) fprintf(stderr, "\n%s\n", full_buf);
           while ((c = getchar()) != '\n')
		     ;
             break;
         }
         msgp->mtext[i] = c;
       }
       msgsz = i;
      } else
        msgsz = 0;

      (void) fprintf(stderr,"\nMeaningful msgsnd flag is:\n");
      (void) fprintf(stderr, "\tIPC_NOWAIT =\t%#8.8o\n",
       IPC_NOWAIT);
      (void) fprintf(stderr, "Enter msgflg: ");
      (void) scanf("%i", &msgflg);
      (void) fprintf(stderr, "%s(%d, msgp, %d, %#o)\n",
                             "msgop: Calling msgsnd", msqid, msgsz, msgflg);
      (void) fprintf(stderr, "msgp->mtype = %ld\n",msgp->mtype);
      (void) fprintf(stderr, "msgp->mtext = \"");

      for (i = 0; i < msgsz; i++)
       (void) fputc(msgp->mtext[i], stderr);

       (void) fprintf(stderr, "\"\n");
       rtrn = msgsnd(msqid, msgp, msgsz, msgflg);

       if (rtrn == -1)
         perror("msgop: msgsnd failed");
       else
        (void) fprintf(stderr,"msgop: msgsnd returned %d\n", rtrn);
       break;

     case 2: /* msgrcv() requested: Get the arguments, make the
                call, and report the results. */
      for (msgsz = -1; msgsz < 0 || msgsz > maxmsgsz;
         (void) scanf("%i", &msgsz))
       (void) fprintf(stderr, "%s (0 <= msgsz <= %d): ",
           "Enter msgsz", maxmsgsz);
      (void) fprintf(stderr, "msgtyp meanings:\n");
      (void) fprintf(stderr, "\t 0 %s\n", first_on_queue);
      (void) fprintf(stderr, "\t>0 %s of given type\n",
       first_on_queue);
      (void) fprintf(stderr, "\t<0 %s with type <= |msgtyp|\n",
          first_on_queue);
      (void) fprintf(stderr, "Enter msgtyp: ");
      (void) scanf("%li", &msgtyp);
      (void) fprintf(stderr,
          "Meaningful msgrcv flags are:\n");
      (void) fprintf(stderr, "\tMSG_NOERROR =\t%#8.8o\n",
          MSG_NOERROR);
      (void) fprintf(stderr, "\tIPC_NOWAIT =\t%#8.8o\n",
          IPC_NOWAIT);
      (void) fprintf(stderr, "Enter msgflg: ");
      (void) scanf("%i", &msgflg);
      (void) fprintf(stderr, "%s(%d, msgp, %d, %ld, %#o);\n",
          "msgop: Calling msgrcv", msqid, msgsz,
          msgtyp, msgflg);
      rtrn = msgrcv(msqid, msgp, msgsz, msgtyp, msgflg);
      if (rtrn == -1)
       perror("msgop: msgrcv failed");
      else {
       (void) fprintf(stderr, "msgop: %s %d\n",
           "msgrcv returned", rtrn);
       (void) fprintf(stderr, "msgp->mtype = %ld\n",
           msgp->mtype);
       (void) fprintf(stderr, "msgp->mtext is: \"");
       for (i = 0; i < rtrn; i++)
        (void) fputc(msgp->mtext[i], stderr);
       (void) fprintf(stderr, "\"\n");
      }
      break;
     default:
      (void) fprintf(stderr, "msgop: operation unknown\n");
      break;
   }
  }
  exit(0);
}

/*
 * Ask the user what to do next. Return the user's choice code.
 * Don't return until the user selects a valid choice.
 */
static int ask()
{
 int response; /* User's response. */

 do {
  (void) fprintf(stderr, "Your options are:\n");
  (void) fprintf(stderr, "\tExit =\t0 or Control-D\n");
  (void) fprintf(stderr, "\tmsgsnd =\t1\n");
  (void) fprintf(stderr, "\tmsgrcv =\t2\n");
  (void) fprintf(stderr, "Enter your choice: ");

  /* Preset response so "^D" will be interpreted as exit. */
  response = 0;
  (void) scanf("%i", &response);
 } while (response < 0 || response > 2);

 return(response);
}
