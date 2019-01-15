#include<stdio.h>
#include "test.h"
extern int  e1 = 100;
void test(void);
int main(void){

  printf("e1=%d\n",e1);
  e1 = 200;

  printf("e1=%d\n",e1);

  printf("e2=%d\n",e2);
  test();
  return 0;
}
