#include<stdio.h>
void reverse(int *a);
void main(){
	int i;
	int a[] = {1,2,3,4,5,6,7,8,9};
	reverse(a);


	for(i = 0;i<9;i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void reverse(int *a){
	int *hi = a+8;
	int *low = a;
	int tmp;
	while(hi > low){
		tmp = *hi;
		*hi = *low;
		*low = tmp;
		hi--;
		low++;
	}

}