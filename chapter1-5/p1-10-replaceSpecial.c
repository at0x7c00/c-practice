#include<stdio.h>
int main(){
	char c;
	while((c = getchar())!=EOF){
		switch(c){
			case '\n':printf("%s","\\n");
			break;
			case '\\':printf("%s","\\\\");
			break;
			case '\t':printf("%s","\\t");
			break;
			default:printf("%c",c);
		}
	}
	return 0;
}