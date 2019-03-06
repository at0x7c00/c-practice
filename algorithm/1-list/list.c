#include<stdio.h>
#include<stdlib.h>
#include "../0-adt/adt.h"
#include "list.h"

int main(){
  List list;
  create_list(&list,1);
  insert(list,1);
  insert(list,2);
  insert(list,3);
  printf("len:%d\n",list_len(list));
  my_print_list(list);
  return 0;
}
void create_list(List *list,element_type value){
  *list = (List)malloc(sizeof(struct Node));
  (*list)->value = value;
  (*list)->next = NULL;
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

void insert(List list,element_type value){
  Position p = (Position)malloc(sizeof(struct Node));
  if(p != NULL){
    p->value = value;
    p->next = list->next;
    list = p;
  }
}

void my_print_list(List list){
  Position p = list->next;
  while(p){
    printf("%d,",p->value);
    p = p->next;
  }
}

int list_len(List list){
  int len = 0;
  Position p = list->next;
  while(p){
    len++;
  }
  return len;
}
