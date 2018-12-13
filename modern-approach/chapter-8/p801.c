#include<stdio.h>
int main(void){
  int num[10] = {0};
  long val;
  printf("Enter a number:");
  scanf("%ld",&val);
  while(val>0){
    int x = val % 10;
    num[x]++;
    val /= 10;
  }

  int i = 0;
  int hasRepeated = 0;
  for(i;i<10;i++){
    if(num[i]>1){
        printf("%d(%d)\n",i,num[i]);
        hasRepeated = 1;
    }
  }
  if(!hasRepeated){
    printf("No repeated digits.");
  }
  return 0;
}
