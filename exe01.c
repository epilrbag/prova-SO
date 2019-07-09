#include <pthread.h>
#include <semaphore.h>

pthread_t t0, t1, t2, t3;
sem_t s0, s1, s2, s3;
int turn = 0;
void *thread_carro0()
{
  while(1)
  {
    sem_wait(&s0);
    //while(turn != 0){}
    printf("Oi, eu sou carro 01 na rua A\nEsperando 5 s pra fechar\n");
    //sleep(5);
    sem_post(&s1);
    //turn = 1;
  }
}

void *thread_carro01()
{
  while(1)
  {
    sem_wait(&s1);
    //while(turn != 1){}
    printf("Oi, eu sou carro 02 na rua B (sentido oposto da rua A)\nEsperando 5 s pra fechar\n");
    sleep(5);
    sem_post(&s2);
    //turn = 2;
  }
}

void *thread_carro02()
{
  while(1)
  {
    sem_wait(&s2);
    //while(turn != 2){}
    printf("Oi, eu sou carro 03 na rua C\nEsperando 5 s pra fechar\n");
    //sleep(5);
    sem_post(&s3);
    //turn = 3;
  }
}

void *thread_carro03()
{
  while(1)
  {
    sem_wait(&s3);
    //while(turn != 3){}
    printf("Oi, eu sou carro 04 na rua D (sentido oposto da rua c)\nEsperando 5 s pra fechar\n");
    sleep(5);
    sem_post(&s0);
    //turn = 0;
  }
}

int main()
{
  sem_init(&s0, 0, 1);
  sem_init(&s1, 0, 1);
  sem_init(&s2, 0, 0);
  sem_init(&s3, 0, 0);
  pthread_create(&t0, NULL, thread_carro0, NULL);
  pthread_create(&t1, NULL, thread_carro01, NULL);
  //sleep(5);
  pthread_create(&t2, NULL, thread_carro02, NULL);
  pthread_create(&t3, NULL, thread_carro03, NULL);
  //sleep(5);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
}
