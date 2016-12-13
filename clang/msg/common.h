#ifndef COMMON_H
#define COMMON_H
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

int register_key(key_t key, int flag);

#endif //COMMON_H 
