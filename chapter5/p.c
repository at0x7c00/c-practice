#include<stdio.h>
void main(){

	int *p;
	int a[10];
	int i = 0;
	p = a;
	for(;i<10;i++){
		scanf("%d",p++);
	}

	p = a;
	for(i=0;i<10;i++){
		printf("%d ", *p++);
	}

	printf("\n");

}