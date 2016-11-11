
int register_key(key_t key, int flag)
{
  int id = msgget( key, flag ); 
  (void) fprintf(stderr, "\nmsgget: Calling msgget(%d,%#o)\n",key, msgflg);

  if ( < 0) {
      perror("msgget");
      exit(1);
  }
  else 
   (void) fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);
}
