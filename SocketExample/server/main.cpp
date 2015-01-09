#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define SERVPORT 3333
#define BACKLOG 10

int main()
{
    /* create socket
     * Format: int socket(int domain, int type, int protocol);
     * Return: Socket File Description (fd)
     *         It's a pointer which points to a socket struct
     * Param : domain=AF_INET (TCP/IP protocol family)...
     *         type=SOCK_STREAM/SOCK_DGRAM...
     *         protocol=0
     */
    // socket file description
    int sock_fd;
    if (-1 == (sock_fd = socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("Create socket failed!");
        exit(1);
    }
    std::cout << "Create socket successfully." << std::endl;

    /* bind socket
     * Format: int bind(int sock_fd,struct sockaddr *my_addr, int addrlen);
     * Return: succ/fail
     * Param : sock_fd from socket() return value
     *         my_addr is a pointer which points to sockaddr struct
     *         addrlen=sizeof(struct sockaddr)
     */
    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(SERVPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 8);
    if (-1 == bind(sock_fd, (struct sockaddr *)&my_addr, sizeof(struct 
    sockaddr)))
    {
        perror("Bind failed!");
        exit(1);
    }
    std::cout << "Bind socket FD successfully." << std::endl;

    /* listen
     * server site will use listen() to wait connection from client site
     * Format: int listen (int sock_fd, int backlog);
     * Return: succ/fail
     * Param : sock_fd from socket() return value
     *         backlog: the maximum of request queue
     * Note  : no need to loop to call this function
     */
    if (-1 == (listen(sock_fd, BACKLOG)))
    {
        perror("Listen failed!");
        exit(1);
    }
    std::cout << "Start to listen sock_fd..." << std::endl;

    while (1)
    {
        int sin_size = sizeof(struct sockaddr_in);
        int client_fd;
        struct sockaddr_in remote_addr;
        /* accept
         * Format: int accept(int sock_fd, void *addr, int *addrlen);
         * Return: a new socket fd for transmitting data/-1 for error
         * Param : sock_fd from socket() return value
         *         addr is a pointer which points to "sockaddr_in"
         *         addrlen is a pointer which points to "sizeof(struct 
         sockaddr_in)
         */
        if (-1 == (client_fd = accept(sock_fd, (struct sockaddr *)&remote_addr, 
        &sin_size)))
        {
            perror("Accept failed!");
            continue;
        }
        // print ip address of client
        std::cout << "Received a connection from " << 
        inet_ntoa(remote_addr.sin_addr) << std::endl;

        /* send traffic: send(), sendto()
         * Format: size_t send(int sock_fd, const void *msg, int len, int 
         flags);
         * Return: the traffic size which have sent/ -1 for error
         * Param : sock_fd from accept() return value
         *         msg: message which we would send to the client
         *         len: length of message
         *         flags = 0
         */
        // you can also call send/receive here
        if (!fork())
        {
            char msg[] = "Hello, you are connected!\n";
            int msg_len = strlen(msg);
            int bytes_sent;
            if (-1 == (bytes_sent = send(client_fd, msg, msg_len, 0)))
            {
                perror("Send failed!");
                close(client_fd);
                exit(0);
            }
            // send successfully
            std::cout << "Already sent out!" << std::endl;
            // close socket
            close(client_fd);
        }
    }
    
    return 0;
}
