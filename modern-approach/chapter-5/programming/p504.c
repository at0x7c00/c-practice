#include<stdio.h>
int main(void){
  int h;
  printf("Enter a level of Wind power:");
  scanf("%d",&h);
  if(h>63){
    printf("Hurricance");
  }else if(h>47){
    printf("Storm");
  }else if(h>27){
    printf("Gale");
  }else if(h>3){
    printf("Breeze");
  }else if(h>=1){
    printf("Light air");
  }else{
    printf("Calm");
  }
  printf("\n");
  return 0;
}
