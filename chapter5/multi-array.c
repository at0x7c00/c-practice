#include<stdio.h>
void print(int (*a)[6]);
void main(){
	int a[4][6];
	int i = 1;
	for(;i<=24;i++){
		*(a++) = i;
	}
	print(a);
}

void print(int (*a)[6]){
	int row = 0;
	int col = 0;
	for(;row<4;row++){
		for(;col<6;col++){
			printf("%d\t",*(*(a+row)+col));	
		}
		printf("\n");
	}
}