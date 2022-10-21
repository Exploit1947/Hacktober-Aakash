#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define PORT 8080
int main()
{
    int sockfd, num, flag;
    struct sockaddr_in servaddr;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))!=(-1))
    {
        printf("Create Socket: S\n");
    }
    else
    {
        printf("Create Socket: F\n");
        exit(0);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    if(connect(sockfd, ((struct sockaddr *)&servaddr), sizeof(servaddr))==0)
    {
        printf("Connection: S\n");
    }
    else
    {
        printf("Connection: F\n");
        exit(0);
    }
    printf("Enter a number to check wether it's odd or even and composite or prime number:\n");
    scanf("%d", &num);
    send(sockfd, &num, sizeof(int), 0);
    recv(sockfd, &flag, sizeof(int), 0);
    if(flag==1)
    {
        printf("Server's Message: (%d) is an even number.", num);
    }
    else
    {
        printf("Server's Message: (%d) is an odd number.", num);
    }
    recv(sockfd, &flag, sizeof(int), 0);
    if(flag==1)
    {
        printf("Server's Message: (%d) is a prime number.", num);
    }
    else
    {
        printf("Server's Message: (%d) is a composite number.", num);
    }
    close(sockfd);
}
