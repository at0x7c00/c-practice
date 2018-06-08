#include<stdio.h>
int isChar(char c);
main(){

	char c;
	int wordStart = 0;
	int wc = 0;
	int res;
	while((c = getchar())!=EOF){

		res = isChar(c);
		if(!wordStart){
			if(res){
				wordStart = 1;	
			}
		}else{
			if(!res){
				wordStart = 0;
				wc++;
			}
		}
	}
	printf("word count:%d\n",wc);

}

int isChar(char c){
   return (c>=65 && c<=90) || (c>=97 && c<=122);
}