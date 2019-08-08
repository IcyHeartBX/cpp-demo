//
// Created by pixboly on 2018/11/30.
//

#include "c_tcp_client.h"
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 6667
#define MAXDATASIZE 100
#define IP "127.0.0.1"

void tcp_client_start(void) {
    const char * TAG = "tcp_client_start()";
    printf("FUNC %s,Run...\n",TAG);
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct sockaddr_in their_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(PORT);
    their_addr.sin_addr.s_addr = inet_addr(IP);
    bzero(&(their_addr.sin_zero),sizeof(their_addr.sin_zero));

    if (connect(sockfd, (struct sockaddr *)&their_addr,sizeof(struct sockaddr)) == -1)
    {
        perror("connect");
        exit(1);
    }
    printf("FUNC %s,connect success!\n",TAG);

    if ((numbytes=recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
    {
        perror("recv");
        exit(1);
    }
    buf[numbytes] = '/0';
    printf("FUNC %s,received:%s\n",TAG,buf);
    close(sockfd);
}
