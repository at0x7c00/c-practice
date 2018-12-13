#include<stdio.h>
#define N 80
//用位移字母加密
int main(void){
  char msg[N];
  char ch;
  int shift;
  int c = 0;
  printf("Enter a message:");
  while((ch = getchar())!='\n' && ch != EOF && c<N){
    msg[c] = ch;
    c++;
  }
  printf("Enter a shift:");
  scanf("%d",&shift);

  int i = 0;
  for(;i<c;i++){
    if(msg[i]>='a'){
      msg[i] = ((msg[i] - 'a') + shift) % 26 + 'a';
    }else if(msg[i]>='A'){
      msg[i] = ((msg[i] - 'A') + shift) % 26 + 'A';
    }
  }
  msg[c] = '\0';
  printf("%s\n", msg);

  printf("Enter a recover shift:");
  scanf("%d",&shift);

  for(i = 0;i<c;i++){
    if(msg[i]>='a'){
      msg[i] = ((msg[i] - 'a') + shift) % 26 + 'a';
    }else if(msg[i]>='A'){
      msg[i] = ((msg[i] - 'A') + shift) % 26 + 'A';
    }
  }
  printf("%s\n", msg);
  return 0;
}
