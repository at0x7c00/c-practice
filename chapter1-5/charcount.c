#include<stdio.h>
int main(){
	int n;
	char c;
	while((c = getchar())!=EOF){
		n++;
	}
	printf("%d chars has bean read.\n",n);
}