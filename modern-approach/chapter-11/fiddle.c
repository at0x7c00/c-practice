#include<stdio.h>
int X = 0;
int f(int* p);
int main(void){
  int i = 5;
  int* p = &i;
  f(p);
  *p = 100;
  printf("X=%d,i=%d",X,i);
  return 0;
}
int f(int* p){
  p = &X;
  *p = 1;
  printf("val of p:%d\n",*p);
  return X + 1;
}
