#include<stdio.h>
#define PRINT(n) printf(#n "= %d\n",n)
#define MK_ID(n) i##n
int main(void){
  int i = 100,j = 200;
  int MK_ID(1) = 0,MK_ID(2) = 0,MK_ID(3) = 0;
  PRINT(j/i);

  printf("%d\n",i1);
  printf("%d\n",i2);
  printf("%d\n",i3);

  return 0;
}
