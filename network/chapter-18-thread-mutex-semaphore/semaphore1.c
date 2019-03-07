#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#define TIMES 1000000
void* increment(void *arg);
void* decrement(void *arg);
int static val;
static sem_t sem_one;
static sem_t sem_two;
int main(void){
  pthread_t t1,t2;

  sem_init(&sem_one,
    0, // pshared:shared by process
    0  // value of semaphore
  );
  sem_init(&sem_two,0,1);

  pthread_create(&t1,NULL,increment,NULL);
  pthread_create(&t2,NULL,decrement,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  sem_destroy(&sem_one);
  sem_destroy(&sem_two);

  printf("value=%d\n",val);
}

void* increment(void *arg){
  int i;
  sem_wait(&sem_one);
  for(i = 0;i<TIMES;i++){
    val++;
  }
  sem_post(&sem_two);
  return NULL;
}

void* decrement(void *arg){
  int i;
  sem_wait(&sem_two);
  for(i = 0;i<TIMES;i++){
    val--;
  }
  sem_post(&sem_one);
  return NULL;
}
