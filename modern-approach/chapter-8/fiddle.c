#include<stdio.h>

int main(void){
  int a[10] = {[1]=1,[8]=8};
  int i = 0;
  for(;i<10;i++){
    printf("%d\n",a[i]);
  }
  int b[5][9] = {
    {1,2,3,4,5,6,7,8,9},
    {1,2,3,4,5},
    {[0]=1,[8]=9}
  };
  for(i = 0;i<5;i++){
    for(int j = 0;j<9;j++){
      printf("%d\t",b[i][j]);
    }
    printf("\n");
  }
  return 0;
}
