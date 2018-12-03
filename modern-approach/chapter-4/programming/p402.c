#include<stdio.h>
/*reverse number with any length*/
int main(void){
  int x;
  printf("Enter a number:");
  scanf("%d",&x);
  while(x>0){
    printf("%d",x % 10);
    x = x/10;
  }
  return 0;
}
