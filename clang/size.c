#include <stdio.h>
#include <string.h>

int main(void)
{
  printf("strlen(\"foo bar\"):\t %zu\n", strlen("foo bar"));
  printf("sizeof(\"foo bar\"):\t %lu\n", sizeof("foo bar"));
  printf("sizeof(char):\t\t %lu\n", sizeof(char));
  printf("sizeof(char):\t\t %lu\n", sizeof(char*));
  printf("sizeof(char):\t\t %lu\n", sizeof(char**));

  return 0;
}
