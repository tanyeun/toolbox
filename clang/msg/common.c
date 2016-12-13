#include "common.h"

int register_key(key_t key, int flag)
{
  int id = msgget( key, flag ); 
  printf("\nmsgget: Calling msgget(%d,%#o)\n",key, flag);

  if ( id < 0) {
      perror("msgget");
	  return -1;
      exit(1);
  }
  else 
    printf("msgget: msgget succeeded: msqid = %d\n", id);

  return id;
}
