#include<stdio.h>
void printArray(int array[],int n);
void initArray(int array[],int len);
int main(void){
  int nums[16];
  int row_sum[4];
  int col_sum[4];
  int diagonal_sum[2];

  initArray(row_sum,4);
  initArray(col_sum,4);
  initArray(diagonal_sum,2);

  printf("Enter the numbers from 1 to 16 in any order:\n");
  int i = 0;
  for(i = 0;i<16;i++){
    scanf("%d",&nums[i]);
  }


  for(i = 0;i<16;i++){
    int row_index = i/4;
    int col_index = i%4;

    row_sum[row_index] += nums[i];
    col_sum[col_index] += nums[i];


    if(row_index == col_index){
      diagonal_sum[0] += nums[i];
    }
    if(row_index + col_index == 3){
      diagonal_sum[1] += nums[i];
    }
  }
  printf("---------------------------------\n");
  for(i = 0;i<16;i++){
    printf("%d\t",nums[i]);
    if((i+1)%4==0){
      printf("|\t%d\n",row_sum[i/4]);
    }
  }
  printf("---------------------------------\n");
  printArray(col_sum,4);
  printf("Diagonal sums:");
  printArray(diagonal_sum,2);

  return 0;
}

void printArray(int array[],int n){
   int i ;
   for(i = 0;i<n;i++){
     printf("%d\t",array[i]);
   }

   printf("\n");

}
void initArray(int array[],int len){
  // int i;
  for(int i = 0;i<len;i++){
    array[i] = 0;
  }
}
