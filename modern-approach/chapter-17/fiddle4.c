#include<stdio.h>
int i = 100,j = 200;
void func(int **p);
int main(void){
  int *p = &i;
  printf("before:%d\n",*p);
  func(&p);
  printf("after:%d\n",*p);
  return 0;
}
void func(int **p){
  *p = &j;
}
