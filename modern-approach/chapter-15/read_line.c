#include<stdio.h>
#include "read_line.h"
int read_line(char *str,int len){
  char ch;
  int i =0;
  while((ch = getchar())!='\n' && ch != EOF && i<len){
    str[i] = ch;
    i++;
  }
  str[i] = '\0';
  return i;
}
