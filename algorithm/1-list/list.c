#include<stdio.h>
#include<stdlib.h>
#include "../0-adt/adt.h"
#include "list.h"
#include "../../error-handing/error_handing.h"
int main(){
  List list = create_list();

  Position p = insert(list,list,1);
  p = insert(list,p,2);
  p = insert(list,p,3);

  print_list(list);

  printf("is empty:%d\n",is_empty(list));
  printf("is last:%d\n",is_last(p));

  p = find(1,list);
  if(p!=NULL){
    printf("find 1 in list\n");
  }
  p = find(4,list);
  if(p==NULL){
    printf("4 is not found in list\n");
  }

  printf("length of list:%d\n",list_len(list));

  delete(list,2);
  print_list(list);

  return 0;
}
//Init a header for a list
List create_list(){
  List list = (List)malloc(sizeof(struct Node));
  return list;
}
//Insert value after position
Position insert(List list,Position position,element_type value){
  Position p = (Position)malloc(sizeof(struct Node));
  if(p == NULL){
    error_handling("malloc() error");
  }
  p->value = value;
  p->next = position->next;
  position->next = p;
  return p;
}
//print elements in list
void print_list(List list){
  Position tmp = list->next;
  while(tmp){
    printf("%d,",tmp->value);
    tmp = tmp->next;
  }
  printf("\n");
}
int is_empty(List list){
  return list->next == NULL;
}

int is_last(Position p){
  return p->next == NULL;
}
Position find(element_type x,List list){
  Position p;
  p = list->next;
  while((p != NULL) && (p->value != x)){
    p = p->next;
  }
  return p;
}
int list_len(List list){
  int len = 0;
  Position p = list->next;
  while(p){
    len++;
    p = p->next;
  }
  return len;
}
void delete(List list,element_type value){
  Position p = list;
  while(p != NULL && p->next->value != value){
    p = p->next;
  }
  if(p!=NULL){
    Position tmp = p->next;
    p->next = tmp->next;
    printf("release a Node:%d\n",tmp->value);
    free(tmp);
  }
}
