#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<errno.h>
void* thread_main(void *arg);
int main(int argc,char *argv[]){
  pthread_t t_id;
  void * thr_ret;
  if(argc != 2){
    printf("Usage:%s <number>\n",argv[0]);
    return 1;
  }
  int params = atoi(argv[1]);
  if(pthread_create(&t_id,NULL,thread_main,(void*)&params)!=0){
    //printf("pthread_create error:%d:%s",errno,strerror(errno));
    printf("%d",errno);
    return 1;
  }
  if(pthread_join(t_id,&thr_ret) != 0){
    printf("%d",errno);
  }
  pthread_detach(t_id);
  printf("%s\n",(char*)thr_ret);
  //free(thr_ret);
  return 0;
}

void* thread_main(void *arg){
  int i;
  int argv = *((int*)arg);
  for(i = 0;i<argv;i++){
    printf("thread is running...\n");
    sleep(1);
  }
  return "value_returned_from_thread";
}
