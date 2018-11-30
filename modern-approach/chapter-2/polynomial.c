#include<stdio.h>
int main(void){
   int x = 0;
   printf("Input a number:");
   scanf("%d",&x);
   x = ((((3 * x + 2) * x - 5 )* x - 1 ) * x + 7 ) * x - 6;
   printf("Result is :%d\n",x);
   return 0;
}
