#include<stdio.h>
int max(int a,int b);
int min(int a,int b);
int sum(int a,int b);
int (*determine(int,int))(int flag);
int process(int a,int b,int (*p)(int,int));

/*Test point to function*/
void main(){

	int x;
	int y;
	scanf("%d",&x);
	scanf("%d",&y);

	printf("x=%d\n", x);
	printf("y=%d\n", y);

	printf("max=%d\n", process(x,y,determine(1)));
	printf("min=%d\n", process(x,y,determine(2)));
	printf("sum=%d\n", process(x,y,determine(3)));

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
int (*determine(int,int))(int flag){
	if(flag == 1){
		return max;
	}else if(flag == 2){
		return min;
	}else{
		return sum;
	}
}