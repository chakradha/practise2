#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int *count;

int num;

int main()
{
    
    int shm;


    shm = shm_open("/sharedMemory", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR );


    ftruncate(shm,sizeof(int));


    count = (int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,shm,0);

    while(1)
    {
        scanf("%d",&num);
        *count = num;
    }

    return 0;
}

