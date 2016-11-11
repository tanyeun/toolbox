/*
 * msgctl.c:  Illustrate the msgctl() function.
 *
 * This is a simple exerciser of the msgctl() function. It allows
 * you to perform one control operation on one message queue.  It
 * gives up immediately if any control operation fails, so be careful
 * not to set permissions to preclude read permission; you won't be
 * able to reset the permissions with this code if you do.
 */
#include   <stdlib.h>
#include   <stdio.h>
#include   <sys/types.h>
#include   <sys/ipc.h>
#include   <sys/msg.h>
#include   <time.h>

static void do_msgctl();
static char warning_message[] = 
     "If you remove read permission for"  
     "yourself, this program will fail frequently!";

int main()
{
  struct msqid_ds buf;     /* queue descriptor buffer for IPC_STAT
                              and IP_SET commands */
	   /* 
	    *  msg_perm: hold permission information
		*    struct ipc_perm
		*      g/uid  : owner's group/user id
		*      cg/uid : creater's group/user id
		*      mode   : access mode 
		*           OWNER GROUP OTHER (9 bits, 3 each)
		*            RWX   RWX   RWX
		*           R = Read
		*           W = Write
		*           X = unused
		*        eg: 0666 => Owner/Group/Other have 
		*                    Rread/Write access
		*      seq    : slot usage sequence number
		*  
		*  msg_cbytes  :   current num of bytes on queue 
	    *  msg_qbytes  :   max number of bytes on queue 
		*  msg_qnum    :   num of msgs current on queue
	    *  msg_lspid   :   pid of last msgsnd 
	    *  msg_lrpid   :   last receive pid 
		*  msg_stime   :   last msgsnd time 
		*  msg_rtime   :   last msgrcv time 
		*  msg_ctime   :   last change time 
	    */
  int    cmd,    /* command to be given to msgctl() */
         msqid;  /* queue ID to be given to msgctl() */
 
  (void) fprintf(stderr,"All numeric input is expected to follow C conventions:\n");
  (void) fprintf(stderr,"\t0x... is interpreted as hexadecimal,\n");
  (void) fprintf(stderr, "\t0... is interpreted as octal,\n");
  (void) fprintf(stderr, "\totherwise, decimal.\n");
 
  /* Get the msqid and cmd arguments for the msgctl() call. */
  (void) fprintf(stderr,"Please enter arguments for msgctls() as requested.");
  (void) fprintf(stderr, "\nEnter the msqid: ");
  (void) scanf("%i", &msqid);

  (void) fprintf(stderr, "\tIPC_RMID = %d\n", IPC_RMID);
  (void) fprintf(stderr, "\tIPC_SET = %d\n", IPC_SET);
  (void) fprintf(stderr, "\tIPC_STAT = %d\n", IPC_STAT);
  (void) fprintf(stderr, "\nEnter the value for the command: ");
  (void) scanf("%i", &cmd);
 
  switch (cmd) {
   case IPC_SET:
     /* Modify settings in the message queue control structure.*/
     (void) fprintf(stderr, "Before IPC_SET, get current values:");
     /* fall through to IPC_STAT processing */
   case IPC_STAT:
     /* Get a copy of the current message queue control
      * structure and show it to the user. */
     do_msgctl(msqid, IPC_STAT, &buf);
     (void) fprintf(stderr, "msg_perm.uid = %d\n", buf.msg_perm.uid);
     (void) fprintf(stderr, "msg_perm.gid = %d\n", buf.msg_perm.gid);
     (void) fprintf(stderr, "msg_perm.cuid = %d\n", buf.msg_perm.cuid);
     (void) fprintf(stderr,"msg_perm.cgid = %d\n", buf.msg_perm.cgid);
     (void) fprintf(stderr, "msg_perm.mode = %#o, ",buf.msg_perm.mode);
     (void) fprintf(stderr, "access permissions = %#o\n",buf.msg_perm.mode & 0777);
     (void) fprintf(stderr, "msg_cbytes = %lu\n", buf.msg_cbytes);
     (void) fprintf(stderr, "msg_qbytes = %lu\n", buf.msg_qbytes);
     (void) fprintf(stderr, "msg_qnum = %lu\n", buf.msg_qnum);
     (void) fprintf(stderr, "msg_lspid = %d\n", buf.msg_lspid);
     (void) fprintf(stderr, "msg_lrpid = %d\n", buf.msg_lrpid);
     (void) fprintf(stderr, "msg_stime = %s", buf.msg_stime ? ctime(&buf.msg_stime) : "Not Set\n");
     (void) fprintf(stderr, "msg_rtime = %s", buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not Set\n");
     (void) fprintf(stderr, "msg_ctime = %s",ctime(&buf.msg_ctime));
     if (cmd == IPC_STAT)
       break;
     /*  Now continue with IPC_SET. */
     (void) fprintf(stderr, "Enter msg_perm.uid: ");
	 (void) scanf ("%i", &buf.msg_perm.uid);
	 (void) fprintf(stderr, "Enter msg_perm.gid: ");
     (void) scanf("%i", &buf.msg_perm.gid);

     (void) fprintf(stderr, "%s\n", warning_message);
     (void) fprintf(stderr, "Enter msg_perm.mode: ");
     (void) scanf("%hi", &buf.msg_perm.mode);

     (void) fprintf(stderr, "Enter msg_qbytes: ");
     (void) scanf("%li", &buf.msg_qbytes);

     do_msgctl(msqid, IPC_SET, &buf);
     break;
   case IPC_RMID:
   default:
    /* Remove the message queue or try an unknown command. */
    do_msgctl(msqid, cmd, (struct msqid_ds *)NULL);
    break;
  }
  exit(0);
}

/*
 * Print indication of arguments being passed to msgctl(), call
 * msgctl(), and report the results. If msgctl() fails, do not
 * return; this example doesn't deal with errors, it just reports
 * them.
 */
static void do_msgctl(msqid, cmd, buf)
struct msqid_ds    *buf;  /* pointer to queue descriptor buffer */
int    cmd,               /* command code */
       msqid;             /* queue ID */
{
  register int rtrn;  /* hold area for return value from msgctl()*/
 
  (void) fprintf(stderr, "\nmsgctl: Calling msgctl(%d, %d,%s)\n",
                 msqid, cmd, buf ? "&buf" : "(struct msqid_ds *)NULL");
  rtrn = msgctl(msqid, cmd, buf);
  if (rtrn == -1) {
    perror("msgctl: msgctl failed");
    exit(1);
  } else {
    (void) fprintf(stderr, "msgctl: msgctl returned %d\n",rtrn);
  }
}
