#include<stdio.h>
int main(){
	char c;
	char pre;
	while((c = getchar())!=EOF){
		if(c !=' ' || pre!=' '){
			printf("%c",c);
			pre = c;	
		}
	}
	return 0;
}