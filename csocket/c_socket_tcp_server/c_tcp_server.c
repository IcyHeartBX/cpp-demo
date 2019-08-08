//
// Created by pixboly on 2018/11/30.
//

#include "c_tcp_server.h"
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define MYPORT 6667
#define BACKLOG 10

void c_tcp_server_start(void) {
    const char * const TAG = "c_tcp_server_start()";
    printf("FUNC %s Run...\n",TAG);
    // def param
    int server_sockfd,client_sockfd;
    struct sockaddr_in server_addr,client_addr;
    int addr_len;
    // socket()
    server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == server_sockfd) {
        printf("FUNC %s,socket error!\n",TAG);
        return ;
    }
    // init server addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(MYPORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero),sizeof(server_addr.sin_zero));
    // bind()
    int bind_res = bind(server_sockfd,(struct sockaddr *) &server_addr,sizeof(struct sockaddr));
    if(bind_res == -1) {
        printf("FUNC %s,bind() error:%d\n",TAG,bind_res);
        perror("bind");
        return ;
    }
    printf("FUNC %s,server bind success!\n",TAG);
    //listen
    int listen_res = listen(server_sockfd,BACKLOG);
    if(listen_res == -1) {
        printf("FUNC %s,listen error!\n",TAG);
        perror("listen");
        return ;
    }
    printf("FUNC %s,server listen success!\n",TAG);
    addr_len = sizeof(struct sockaddr_in);
    //looper accept
    while(1) {
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }
        printf("FUNC %s,accept client connect success IP:%s\n", TAG, inet_ntoa(client_addr.sin_addr));
        if (!fork()) {
            if (send(client_sockfd, "Hello,i am server!\n\0", 20, 0) == -1) {
                perror("send");
            }
            printf("FUNC %s,send msg success!\n", TAG);
            close(client_sockfd);
            exit(0);
        }
    }
}
