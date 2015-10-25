/*
 * testmain.c
 *
 *  Created on: Oct 24, 2015
 *      Author: dcipher
 */
// include statements

#include "testmain.h"

int tests(int argc, char * argv[])
{
	char arg[3];
	arg[0] = '-';
	arg[1] = 'c';
	arg[2] = 0;
	correctArgs(arg);
	arg[0] = '-';
	arg[1] = 's';
	arg[2] = 0;
	correctArgs(arg);
	printf("number of arguments: %d\n", argc);
	printf("length of %s is %lu\n",argv[1],strlen(argv[1]));
	if(correctNumberOfArguments(&argc) && correctArgs(argv[1]))
	{
		//run
		short portno = 10600;
		int sockfd;
		int clientsocket;
		int c;
		int read_size;
		struct sockaddr_in server;
		struct sockaddr_in client;
		char clientMSG[512];
		int bindstate = 0;
		int listenstate = 0;

		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd < 0)
		{
			perror("could not create socket");
		}
		puts("socket created");

		server.sin_family = AF_INET;
		server.sin_addr.s_addr = INADDR_ANY;
		server.sin_port = portno;

		bindstate = bind(sockfd,(struct sockaddr *)&server, sizeof(server));

		if(bindstate < 0)
		{
			perror("Error: bind failed");
		}
		puts("bind done");

		listenstate = listen(sockfd,5);
		if(listenstate < 0)
		{
			perror("Error listen() call returned status -1");
		}
		puts("waiting for incoming connections");

		c = sizeof(struct sockaddr_in);

		clientsocket = accept(sockfd, (struct sockaddr *)&client, (socklen_t*)&c);
		if(clientsocket < 0)
		{
			perror("accept failed");
		}
		puts("connection accepted");

		read_size = recv(clientsocket,clientMSG,512,0);
		char * msgcheck = 0;
		while(read_size >
 0)
		{
			printf("message: %s",clientMSG);
			//strncasecmp()
			msgcheck = strstr(clientMSG,"close");
			send(clientsocket,clientMSG,strlen(clientMSG),0);
			if(msgcheck == 0)
			{
				read_size = recv(clientsocket,clientMSG,512,0);
			}
			else
			{
				read_size = 0;
			}
		}

		if(read_size == 0)
		{
			puts("client disconnected");
			fflush(stdout);
		}
		else if(read_size == -1)
		{
			perror("recv ended with code -1");
		}
	}
	else
	{
		printf("malformed command, specify run mode\nusage:\n");
		printf("for server mode\n%s -s\n",argv[0]);
		printf("for client mode\n%s -c\n",argv[0]);
		exit(0); //return 0;
	}
	//typesizereference();
	return 0;
}
void typesizereference()
{
	printf("size of int: %lu\n",sizeof(int));
	printf("size of short: %lu\n",sizeof(short));
	printf("size of u_short: %lu\n",sizeof(u_short));
	printf("size of uint16_t: %lu\n",sizeof(uint16_t));
}
