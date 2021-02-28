#include <iostream>
#include <string>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

int sending_client(char *message, int port, char * host)
{
//Creating the buffer for the file
char buffer[254];
FILE *stream;
stream=fmemopen(message,strlen(message),"r");
int num_char_read=fread(buffer+1,sizeof(char),sizeof(buffer),stream);
buffer[0]=num_char_read;

sockaddr_in server_address={0};
// Create socket
int sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
    perror("Failed to Create the socket");
    exit(EXIT_FAILURE);
    return -1;
}
//Configure the Connection
server_address.sin_family=AF_INET;
server_address.sin_port=htons(port);
inet_pton(AF_INET, host, &(server_address.sin_addr));
memset(&(server_address.sin_zero),'\0',8);
int sending=sendto(sockfd,(const char*)buffer,strlen(buffer)+1,0,(const struct sockaddr*)&server_address,sizeof(server_address));
if(sending==-1)
{
    perror("Failure to send packager");
    exit(EXIT_FAILURE);
    close(sockfd);
    return -1;
}
close(sockfd);
return 1;
}


