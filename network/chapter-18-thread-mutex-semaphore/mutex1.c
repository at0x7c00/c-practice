#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define TIMES 1000000
int static val;
void* increment(void *arg);
void* decrement(void *arg);
pthread_mutex_t mutex;
int main(void){
  pthread_t t1,t2;

  pthread_mutex_init(&mutex,NULL);

  pthread_create(&t1,NULL,increment,NULL);
  pthread_create(&t2,NULL,decrement,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  pthread_mutex_destroy(&mutex);

  printf("value=%d\n",val);
}

void* increment(void *arg){
  int i;
  for(i = 0;i<TIMES;i++){
    pthread_mutex_lock(&mutex);
    val++;
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void* decrement(void *arg){
  int i;
  for(i = 0;i<TIMES;i++){
    pthread_mutex_lock(&mutex);
    val--;
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}
