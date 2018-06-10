 #include<stdio.h>
void strcopy(char *s,char *t);
main(){

	int *pa;
	int x[10];

	int i = 0;
	for(i = 0;i<10;i++){
		x[i] = i;
	}

	pa = &x[2];

	pa--;
	pa--;
	pa--;

	printf("%d\n", *(pa+1)+1);

	char *message = "This is Message!";
	printf("%s\n", message);

	char amessage[16];
	strcopy(amessage,message);

	printf("....%s\n", amessage);

}


void strcopy(char *s,char *t){

	int i = 0;
	while((*s = *t)!='\0'){
		s++;
		t++;
	}
}