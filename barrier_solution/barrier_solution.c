#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_barrier_t init_barrier;
void *i2c_thread(void *data)
{
    printf("\nI2C init is Started");
    sleep(3);
    pthread_barrier_wait(&init_barrier);
    printf("\nI2C is completed");
}
void *eeprom_thread(void *data)
{
    printf("\nEEPROMinit is Started");
    sleep(3);
    pthread_barrier_wait(&init_barrier);
    printf("\nEEPROM is completed");
}
void *Uart_thread(void *data)
{
    printf("\nUART init is Started");
    sleep(3);
    pthread_barrier_wait(&init_barrier);
    printf("\nUART is completed");
}
void *eth_thread(void *data)
{
    printf("\nethinit is Started");
    sleep(6);
    pthread_barrier_wait(&init_barrier);
    printf("\neth is completed");
}


int main()
{
    pthread_barrier_init(&init_barrier,NULL,4);
    pthread_t i2c,eth,uart,eeprom;
    pthread_create(&i2c,NULL,i2c_thread,NULL);
    pthread_create(&eth,NULL,eth_thread,NULL);
    pthread_create(&eeprom,NULL,eeprom_thread,NULL);
    pthread_create(&uart,NULL,Uart_thread,NULL);
    pthread_join(i2c,NULL);
    pthread_join(eth,NULL);
    pthread_join(eeprom,NULL);
    pthread_join(uart,NULL);
}