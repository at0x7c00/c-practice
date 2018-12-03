#include<stdio.h>
int main(void){
  int h,m;
  printf("Enter a 24-hour time:");
  scanf("%d:%d",&h,&m);
  if(h>=24){
    h -= 24;
  }
  printf("Equivalent 12-hour time:%d:%d %s",
  (h>12 ? h - 12:h),
  m,
  (h>=12 ? "PM":"AM"));
  return 0;
}
