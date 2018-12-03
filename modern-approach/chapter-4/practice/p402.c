#include<stdio.h>
int main(void){
  int i = 8,j = 5;
  printf("%d / %d = %d\n",i,j,i/j);
  printf("%d \% %d = %d\n",i,j,i%j);

  i = -8;
  printf("%d / %d = %d\n",i,j,i/j);
  printf("%d \% %d = %d\n",i,j,i%j);
  i = 8;
  j = -5;
  printf("%d / %d = %d\n",i,j,i/j);
  printf("%d \% %d = %d\n",i,j,i%j);
  i = -8;
  printf("%d / %d = %d\n",i,j,i/j);
  printf("%d \% %d = %d\n",i,j,i%j);
  return 0;
}
