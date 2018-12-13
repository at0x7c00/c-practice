#include<stdio.h>
#define N 100
/*reversal of sentence*/
int main(void){
  char sentences[N];
  char ch;
  printf("Enter a sentence:");
  int i = 0;
  char end;
  while((ch = getchar())!='\n' && i<N){
    if(ch == '?' ||  ch == '.' || ch == '!'){
      end = ch;
      break;
    }else{
      sentences[i] = ch;
      i++;
    }
  }
  sentences[i] = '\0';
  //printf("%s,i=%d\n",sentences,i);
  int word_len = 0;
  for(i--;i>=0;i--){
    word_len++;
    if(sentences[i] == ' ' || i == 0){
      int j = i==0 ? 0 : 1;
      for(;j<word_len;j++){
        printf("%c",sentences[i + j]);
      }
      if(i>0){
          printf("%c",sentences[i]);
      }
      word_len = 0;
    }
  }

  printf("%c",end);
  return 0;
}
