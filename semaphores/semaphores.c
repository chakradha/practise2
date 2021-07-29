#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int a , b ,sum;
sem_t s1;
sem_t s2;
void *input_thread(void *data)
{
    while(1)
    {
        sem_wait(&s1);
        printf("\nEnter the value of a :");
        scanf("%d",&a);
        printf("\nEnter the valueof b :");
        scanf("%d",&b);
        sem_post(&s2);

    }
}
void *proc_thread(void *data)
{
    sem_wait(&s2);
    sum = a+b;
    printf("\n SUM =  %d",sum);
    sem_post(&s1);

}


int main()
{
pthread_t input_t,proc_t;
sem_init(&s2,0,1);
sem_init(&s1,0,1);
pthread_create(&input_t,NULL,input_thread,NULL);
pthread_create(&proc_t,NULL,proc_thread,NULL);
pthread_join(input_t,NULL);
pthread_join(proc_t,NULL);
sem_destroy(&s1);
sem_destroy(&s2);

}