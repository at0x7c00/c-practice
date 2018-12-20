#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Message{
  int id;
  char *content;
  struct Message *next;
};
char *read_line();
void print_msgs(struct Message *msgs);
struct Message *searchbyid(struct Message *msgs,int id);
struct Message *insert(struct Message *msgs,int id,char *content);
struct Message *delete(struct Message *msgs,int id);
/*****************************************
read line and save to a link
********************************************/
int main(void){
  struct Message *msgs = NULL;
  struct Message *tail = NULL;
  char cmd[20];
  printf("Insert command:insert,update,delete,show or exit\n");
  while(1){
     scanf("%s",cmd);
     if(strlen(cmd)==0){
       continue;
     }
     if(strcmp(cmd,"exit")==0){
       return 0;
     }
     if(strcmp(cmd,"show")==0){
       print_msgs(msgs);
       continue;
     }
     if(strcmp(cmd,"insert")==0){
        int id;
        scanf("%d",&id);
        if(searchbyid(msgs,id)){
          printf("Id Repeated!\n");
          continue;
        }
        msgs = insert(msgs,id,read_line());
     }else if(strcmp(cmd,"delete")==0){
       int id;
       scanf("%d",&id);
       struct Message *p = searchbyid(msgs,id);
       if(!p){
         printf("No record found by id=%d\n",id);
       }else{
         msgs = delete(msgs,id);
       }
     }else if(strcmp(cmd,"update")==0){
       int id;
       scanf("%d",&id);
       struct Message *p = searchbyid(msgs,id);
       if(!p){
         printf("No record found by id=%d\n",id);
       }else{
         p->content = read_line();
       }
     }else{
       printf("command not found.\n");
     }
  }
  return 0;
}
void print_msgs(struct Message *msgs){
  if(!msgs){
    printf("No Record.\n");
    return;
  }
   while(msgs){
     printf("[%d]:%s\n",msgs->id,msgs->content);
     msgs = msgs->next;
   }
}
struct Message *searchbyid(struct Message *msgs,int id){
  while(msgs){
    if(msgs->id == id){
      return msgs;
    }
    msgs = msgs->next;
  }
  return NULL;
}
struct Message *delete(struct Message *msgs,int id){
  struct Message *curr,*prev;
  for(prev = NULL,curr = msgs ; curr != NULL && curr->id != id;prev = curr,curr = curr->next)
    ;
  if(!curr){
    //not found
    return msgs;
  }
  struct Message *tmp;
  if(prev==NULL){//find at first node of link
    tmp = curr;
    curr = curr->next;
    free(tmp);
    return curr;
  }else{
    prev->next = curr->next;
    free(curr);
  }
  return msgs;
}
char *read_line(){
  int init_size = 10;
  int count = 0;
  char *p = (char *)malloc(init_size);
  char ch;
  while((ch = getchar())!='\n' && ch != EOF){
    p[count] = ch;
    count++;
    if(count>=init_size-1){
      init_size*=2;
      p = realloc(p,init_size);
    }
  }
  p[count] = '\0';
  return p;
}
struct Message *insert(struct Message *msgs,int id,char *content){
  struct Message *curr,*prev;
  //find first record lower than new item
  for(prev = NULL,curr = msgs ; curr != NULL && curr->id < id;prev = curr,curr = curr->next)
    ;
  if(curr){
    scanf("curr:%d\n",curr->id);
  }

  struct Message *p =  malloc(sizeof(struct Message));
  p->id = id;
  p->content = content;
  //new link
  if(!msgs){
    return p;
  }

  if(prev==NULL){
    // find at first position
    p->next = curr;
    return p;
  }else{
    // insert into link
    prev->next = p;
    p->next = curr;
    return msgs;
  }
}
