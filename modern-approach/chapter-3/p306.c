#include<stdio.h>
int main(void){
  int a,b,c,d;
  int result_num;
  int result_denom;
  printf("Enter two fractions separated by a plus sign:");

  scanf("%d/%d+%d/%d",&a,&b,&c,&d);

  result_num = a * d + c * b;
  result_denom = b * d;
  printf("The sum is %d/%d",result_num,result_denom);

  return 0;
}
