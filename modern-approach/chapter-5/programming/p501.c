#include<stdio.h>
int main(void){
  int num;
  int tmp;
  printf("Enter a number:");
  scanf("%d",&num);

  tmp = num;
  int c = 0;
  while(tmp != 0){
     c++;
     tmp = tmp / 10;
  }
  printf("The number %d has %d digits.",num,c);
  return 0;
}
