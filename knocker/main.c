#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int send_packet(char *addr,uint32_t port,char *text)
{
    int fd,err,sas;
    struct sockaddr_in sa;
    
    sas = sizeof(sa);

    printf("%s, %u, %s\n",addr,port,text);

    memset((char *) &sa, 0, sizeof(sa));

    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    
    if(inet_aton(addr, &sa.sin_addr) == 0)
    {
        printf("address");
        return 0;
    }


    fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(fd < 0)
    {
        printf("socket");
        return 0;
    }

    err = sendto(fd,text,strlen(text),0,(struct sockaddr *)&sa,sas);
    
    if(err < 0)
    {
        perror("fail: ");
    }
    printf("sent\n");

    close(fd);
    
    return 0;
}


int main(int argc,char **argv)
{
    if(argc != 4)
    {
        printf("invalid parameters\n");
        return -1;
    }

    uint32_t port = (uint32_t)atoi(argv[2]);

    printf("%s, %u, %s\n", argv[1], port,argv[3]);
    send_packet(argv[1], port,argv[3]);
    return 0;
}
