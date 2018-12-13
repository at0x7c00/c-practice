#include<stdio.h>
#include<limits.h>
int countInput();
int main(void){
/*
printf("Enter a message:");
int c = countInput();
printf("Your message was %d character(s) long.",c);
*/
  typedef int Bool;
  Bool x = 5;
  printf("%d",x);

  return 0;
}


int countInput(){

  int c = 0;
  while((getchar()!='\n')){
    c++;
  }
  return c;
}
