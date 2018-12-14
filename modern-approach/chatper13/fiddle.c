#include<stdio.h>
int main(void){
  char p[] = "Hello";
  char *q = p;
  q[1] = 'A';
  printf("%s\n", p);
  return 0;
}
