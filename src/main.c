//// include statements

#include <stdio.h>
#include <ctype.h>
#define MAXBUFFERSIZE   80
#include <stdio.h>
 // for printf(), scanf(), NULL, FILE, fopen()
#include <unistd.h>
 // for sleep()
#include <stdbool.h>
 // for bool type
#include <stdlib.h>
 // for malloc() & free()
#include <string.h>
 // for strlen(), strcmp(), memcpy() & memset()
#include <stdlib.h>
 // for srand(), rand()
#include <time.h>
 // for time()
#include <sys/socket.h>
 // for socket()
#include <sys/types.h>
 // for stat() and struct stat and pthread types
#include <sys/stat.h>
 // for stat() and struct stat type
#include <pthread.h>
 // for pthread function calls and pthread types
#include <netinet/in.h>
 // for struct in_addr

#include "intuitiveStringOps.h"
#include "specifics.h"
#include "testmain.h"

// ############################################################################
// constant and variable definitions
// ############################################################################
// function signatures

//void clienConnectionHandler(int pServerSocket);
//void serverConnectionHandler(int pClientSocket);

int initServerSocket(short * pClientSocket);
//int initClientSocket(u_short * pServerSocket);

//void actAsClient(u_short * pPortNo);
//void actAsServer(short * pPortNo);

//void connection_handler(int pClientSocket, bool * work);

//int initSocket(short * pPortNo);

//void runtime();

// ############################################################################
// main function definition

int main(int argc, char * argv[])
{
    tests(&argc,argv);
    //if(correctNumberOfArguments(&argc) && correctArgs(argv[1]))
    if(correctNumberOfArguments(&argc) && correctArgs(argv[1]) && false)
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
        while(read_size > 0)
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
    return 0;
}

void run()
{
    char    ch;                     /* handles user input */
    char    buffer[MAXBUFFERSIZE];  /* sufficient to handle one line */
    int     char_count;             /* number of characters read for this line */
    int     exit_flag = 0;
    int     valid_choice;

    while(exit_flag == 0)
    {
        printf("Enter a line of text (<80 chars)\n");
        ch = getchar();
        char_count = 0;
        while((ch != '\n')  &&  (char_count < MAXBUFFERSIZE))
        {
            buffer[char_count++] = ch;
            ch = getchar();
        }
        buffer[char_count] = 0x00;      /* null terminate buffer */
        printf("\nThe line you entered was:\n");
        printf("%s\n", buffer);

        valid_choice = 0;
        while(valid_choice == 0)
        {
            printf("Continue (Y/N)?\n");
            scanf(" %c", &ch );
            ch = toupper( ch );
            if((ch == 'Y') || (ch == 'N'))
                valid_choice = 1;
            else
                printf("\007Error: Invalid choice\n");
            cleartoendofline();
        }
        if(ch == 'N')
            exit_flag = 1;
    }
}

void runtime()
{
//    bool menu = true;
//    while (menu)
//    {
//        if(!menu)
//        {
//            break;
//            printf("goodbye!\n");
//        }
//        printf("what do you want to do?\n");
//        int choice = 0;
//        //cin>>choice;
//        scanf()
//        printf("the choice is: %d\n",choice);
//    }
}
// ############################################################################
// function definitions

/**********************************************************************/
/* This function starts the process of listening for web connections
 * on a specified port.
 * Parameters: pointer to variable containing the port to connect on
 * Returns: the socket */
/**********************************************************************/
int initServerSocket(short * pClientSocket)
{
    int sockfd = 0;
    //int httpd = 0;
    struct sockaddr_in name;

    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    int opt = 1; //option value
    /*option to reuse the port assigned*/
    int setopt = 0;
    setopt = setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));

    if (setopt < 0)
    {
        perror("set reuse port option");
        exit(1);
    }

    memset(&name, 0, sizeof(name));
    name.sin_family = AF_INET;
    name.sin_port = htons(*pClientSocket);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd, (struct sockaddr *)&name, sizeof(name)) < 0)
    {
        perror("bind");
        exit(1);
    }

    if(listen(sockfd, 5) < 0)
    {
        perror("listen");
        exit(1);
    }
    return sockfd;
}
