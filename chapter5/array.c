#include<stdio.h>
void main(){

	int a[2][2] = {
		{1,2},
		{3,4}
	};

	printf("%d\n",*(a[0]+3));

}