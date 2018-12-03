#include<stdio.h>

int main(void){
  int x;
  int r[5] = {0,0,0,0,0};
  printf("Enter a number between 0 and 32767:");
  scanf("%d",&x);
  //printf("In Octal,your number is :%o",x);
  int i = 0;
  while(x>0){
    r[i] = (x % 8);
    x = x / 8;
    i++;
  }
  for(i = 4;i>=0;i--){
    printf("%d",r[i]);
  }
  return 0;
}
