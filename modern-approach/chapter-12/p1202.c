#include<stdio.h>
#define N 50
int main(void){
  char data[N];
  char ch;
  char *tail = &data[0];
  char *head = &data[0];
  char *x = data;
  printf("Enter a message:");
  while((ch = getchar())!='\n' && tail < data + N){
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)){
       if(ch >= 97){
          ch -= 32;
       }
       *tail = ch;
       tail++;
    }
  }
  --tail;
  while(tail-- > head++){
    if(*tail != *head){
        printf("No",*head,*tail);
        return 0;
    }
  }
  printf("Yes");

  return 0;
}
