#include<stdio.h>
int main(){
	int spaceCount = 0,tabCount = 0,lineCount = 0;
	char c = getchar();
	while(c!=EOF){
		switch(c){
			case ' ': spaceCount++;break;
			case '\t': tabCount++;break;
			case '\n': lineCount++;break;
		}
		c = getchar();
	}
	printf("char read stat:\nSpace:%d\n\\t:%d\n\\n:%d\n",spaceCount,tabCount,lineCount);
	return 0;
}