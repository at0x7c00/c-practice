#include<stdio.h>
/*reverse a two-digit number*/
int main(void){
  int x;
  printf("Enter a two-digit number:");
  scanf("%d",&x);
  printf("%d",x % 10);
  printf("%d",(x - (x % 10))/10);
  return 0;
}
