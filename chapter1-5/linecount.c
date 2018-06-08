#include<stdio.h>
int main(){
	int n;
	char c;
	while((c = getchar())!=EOF){
		if(c=='\n'){
			n++;	
		}
	}
	printf("%d lines has bean read.\n",n);
}