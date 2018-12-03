#include<stdio.h>

int main(void){
  int area_code;
  printf("Enter an area code(0 to exit):");
  scanf("%d",&area_code);
  while(area_code!=0){
    switch(area_code){
      case 229:printf("Albany");break;

      case 770:
      case 404:
      case 470:
      case 678:printf("Atlanta");break;

      case 478:printf("Macon");break;
      case 706:
      case 762:printf("Columbus");break;

      case 912:printf("Savannah");break;
      default:printf("Area code not recognized");
      break;
    }
    printf("\nEnter an area code(0 to exit):");
    scanf("%d",&area_code);
  }

  return 0;
}
