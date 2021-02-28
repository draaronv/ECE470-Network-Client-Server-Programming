#include <iostream>
#include <string>
#include <string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define BACKLOG 5
#define SERVER_PORT 12345
#define CLIENT_PORT 3333
#define MAXBUFFERLEN 1024
#define SERVER_ROUTE localhost
using namespace std;

class client
{
    private:
        int sockfd_server;
        int sockfd_client;
        int sockfd_client_acc;
        string server_route;
        string client_route;
        int server_port;
        int client_port;
        sockaddr_in server_address={0};
        sockaddr_in client_address={0};
    public:
        client()
        {
            sockfd_server=socket(AF_INET,SOCK_STREAM,0);
            sockfd_client=socket(AF_INET,SOCK_STREAM,0);
            if(sockfd_server==-1)
            {
                perror("Failed to create socket for communicating with the server");
                exit(EXIT_FAILURE);
            }
            if(sockfd_client==-1)
            {
                perror("Failed to create socket for listening for message from Server");
                exit(EXIT_FAILURE);
            }
            //To send messages
            server_address.sin_family=AF_INET;
            server_address.sin_port=htons(SERVER_PORT);
            inet_pton(AF_INET,server_route.c_str(),&(server_address.sin_addr));
            memset(&(server_address.sin_zero),'\0',8);

            //To make the client listen
            client_address.sin_family=AF_INET;
            client_address.sin_port=CLIENT_PORT;
            server_address.sin_addr.s_addr=INADDR_ANY;
            memset(&(client_address.sin_zero),'\0',8);
        }

        int send_message(char *message)
        {
            char buffer[MAXBUFFERLEN];
            FILE *stream;
            stream=fmemopen(message,strlen(message),"r");
            int num_char_read=fread(buffer+1,sizeof(char),sizeof(buffer),stream);
            buffer[0]=num_char_read;
            int connection=connect(sockfd_server,(const struct sockaddr*)&server_address,sizeof(struct sockaddr));
            if(connection==-1)
            {
                perror("Failure to connect to server");
                exit(EXIT_FAILURE);
                close(sockfd_server);
                return -1;
            }
            int sending=send(sockfd_server,(const char*) buffer,strlen(buffer)+1,0);
            if(sending==-1)
            {
                perror("Failure to send packager");
                exit(EXIT_FAILURE);
                close(sockfd_server);
                return -1;
            }
            return 1;
        }

        string listen_message()
        {
            FILE *stream;
            char *bp;
            size_t size;
            stream=open_memstream(&bp,&size);
            char buffer[MAXBUFFERLEN];
            int rc=bind(sockfd_client,(const struct sockaddr*)&client_address,sizeof(client_address));
            if(rc==-1)
            {
                perror("Failed to bind client_address to socket");
                close(sockfd_client);
                exit(EXIT_FAILURE);
            }
            int listening=listen(sockfd_client,BACKLOG);
            if(listening==-1)
            {
                perror("Failed to listen to socket");
                close(sockfd_client);
                exit(EXIT_FAILURE);
            }
            unsigned int sin_size=sizeof(struct sockaddr_in);
            sockfd_client_acc=accept(sockfd_client,(struct sockaddr *)&server_address,&sin_size);
            int received=recv(sockfd_client_acc,(char *)buffer,MAXBUFFERLEN,0);
            if(received==-1)
            {
                perror("Failed to received package");
                close(sockfd_client);
                close(sockfd_client_acc);
                exit(EXIT_FAILURE);
            }
            fwrite(buffer+1,sizeof(char),buffer[0],stream);
            fflush(stream);
            string temp(bp);
            return temp;
        }

};

