#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include "error_handing.h"
void error_handling(char *msg){
  fputs(msg,stderr);
  fputs(":",stderr);
  printf("%d:%s\n",errno,strerror(errno));
  fputs("\n",stderr);
  exit(1);
}
