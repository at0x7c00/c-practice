#include<stdio.h>
#define N 50
void version1();
void version2();

int main(void){
  version1();
  return 0;
}

void version2(void){
  char msg[N];
  char ch;
  printf("Enter a message:");
  char *p = &msg[0];
  int i = 0;
  while((ch = getchar())!='\n' && p < msg + N){
    *p = ch;
     p++;
  }
  p--;
  while(p>=msg){
    printf("%c",*p);
    p--;
  }

}
void version1(void){
  char msg[N];
  char ch;
  printf("Enter a message:");
  int i = 0;
  while((ch = getchar())!='\n' && i < N){
    msg[i] = ch;
    i++;
  }
  i--;
  for(;i>=0;i--){
     printf("%c",msg[i]);
  }
}
