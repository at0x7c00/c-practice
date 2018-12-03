#include<stdio.h>
#include<limits.h>
int main(void){
  printf("%d\n",sizeof(short int));
  printf("%d\n",sizeof(int));
  printf("%d\n",sizeof(long int));



  printf("max sort:%d\n",SHRT_MAX);
  printf("max int:%d\n",INT_MAX);
  printf("max long:%d\n",LONG_MAX);



  return 0;
}
