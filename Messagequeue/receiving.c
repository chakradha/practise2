#include<stdio.h>
   
#include <fcntl.h>

#include <sys/stat.h>
#include<mqueue.h>


mqd_t message;
struct mq_attr message_attr;
char buffer[128];
int msg_prio;
int main()
{
    
    message_attr.mq_flags = 0;
    message_attr.mq_maxmsg = 4;
    message_attr.mq_msgsize = 128;
    message_attr.mq_curmsgs = 0;
    message = mq_open("/message",O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR,&message_attr);
    mq_receive(message,buffer,128,&msg_prio);
    printf("Received Message is %s \n Message prio = %d\n",buffer,msg_prio);
    mq_close(message);
    return 0;

}

