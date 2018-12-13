#include<stdio.h>
#include<ctype.h>
#define ADD 1
#define DEL 0
#define N 30
int enter_word(int record[],char *tip,int operation);
int do_record(int record[],char ch,int operation);
//变位词判断
int main(void){
  int record[26] = {};
  if(!enter_word(record,"Enter first word:",ADD)){
    return 0;
  }
  if(!enter_word(record,"Enter second word:",DEL)){
    return 0;
  }
  int i;
  for(i=0;i<26;i++){
    if(record[i]!=0){
      printf("No");
      return 0;
    }
  }
  printf("Yes");
  return 0;
}

int enter_word(int record[],char *tip,int operation){
  printf("%s",tip);
  char ch;
  while((ch = getchar()) != '\n' && ch != EOF){
    if(!do_record(record,ch,operation)){
      return 0;
    }
  }
  return 1;
}

int do_record(int record[],char ch,int operation){
  if(!isalpha(ch)){
    printf("is Not a word!");
    return 0;
  }
  ch = tolower(ch);
  if(operation == ADD){
      record[ch - 'a']++;
  }else if(operation == DEL){
      record[ch - 'a']--;
  }
  return 1;
}
