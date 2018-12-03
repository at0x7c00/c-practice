#include<stdio.h>
int main(void){
  printf("Hello,World");
  int a = 120;
  int i;
  for(i = 0; i<100; i++){
    printf("%d\n",i);
  }
  int x = 100;
  x = x + 20;
  printf("%d,%d",a,x);
  return 0;
}
