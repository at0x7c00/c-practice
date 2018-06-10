#include<stdio.h>
int max(int a,int b);
int min(int a,int b);
int sum(int a,int b);

int process(int a,int b,int (*p)(int,int));
/*Test point to function*/
void main(){

	int x;
	int y;
	scanf("%d",&x);
	scanf("%d",&y);

	printf("x=%d\n", x);
	printf("y=%d\n", y);

	printf("max=%d\n", process(x,y,max));
	printf("min=%d\n", process(x,y,min));
	printf("sum=%d\n", process(x,y,sum));

}

int process(int a,int b,int (*p)(int,int)){
	return (*p)(a,b);
}

int max(int a,int b){
	return a > b ? a : b;
}
int min(int a,int b){
	return a > b ? b : a;
}
int sum(int a,int b){
	return a + b;
}