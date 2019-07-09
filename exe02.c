#include <pthread.h>
#include <semaphore.h>
#define memoria 132

pthread_t t0, t1, t2, t3;
sem_t s0, s1, s2, s3;
char buffer[memoria];

void *leitor()
{
  char palavra[memoria];
  sem_wait(&s0);
  for(int i = 0; i < memoria; i++)
  {
    scanf("%c", &palavra[i]);
    if(palavra[i] == 'D')
      break;
    else
      buffer[i] = palavra[i];
  }
  sem_post(&s1);
}

void *impressor()
{
  sem_wait(&s1);
  for(int i = 0; i < memoria; i++)
    printf("%c", buffer[i]);
  sem_post(&s0);
}

int main()
{
  sem_init(&s0, 0, 1);
  sem_init(&s1, 0, 0);

  pthread_create(&t0, NULL, leitor, NULL);
  pthread_create(&t1, NULL, impressor, NULL);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
}
