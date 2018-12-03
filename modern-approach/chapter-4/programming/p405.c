#include<stdio.h>
/*Use length to limit input of scanf*/
int main(void){
  int a,b,c;
  printf("Enter the first 11 digits of a UPC:");
  scanf("%1d",&a);
  scanf("%5d",&b);
  scanf("%5d",&c);

  printf("%d-%d-%d",a,b,c);

  return 0;
}
