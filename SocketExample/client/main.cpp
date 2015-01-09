/* g++ -g -O3 -o SocketClient main.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define SERVPORT 3333
#define PARAM_NUM 2
#define MAX_DATA_SIZE 100

int main(int argc, char *argv[])
{
    if (PARAM_NUM != argc)
    {
        std::cout << "Usage: ./SocketClient <hostname>" << std::endl;
        return 0;
    }

    /* get ip address of server
     * Format: struct hostent *gethostbyname(const char *name);
     */
    struct hostent *host;
    if (NULL == (host = gethostbyname(argv[1])))
    {
        herror("gethostbyname failed!");
        exit(1);
    }

    /* create socket
     * Format: int socket(int domain, int type, int protocol);
     * Return: Socket File Description (fd)
     *         It's a pointer which points to a socket struct
     * Param : domain=AF_INET (TCP/IP protocol family)...
     *         type=SOCK_STREAM/SOCK_DGRAM...
     *         protocol=0
     */
    int sock_fd;
    if (-1 == (sock_fd = socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("Create socket failed!");
        exit(1);
    }
    std::cout << "Create socket successfully." << std::endl;

    /* create a TCP connection with server
     * Format: int connect(int sock_fd, struct sockaddr *serv_addr, int 
     addrlen);
     * Return: succ/fail
     * Param : sock_fd from socket() return value
     *         serv_addr: server ip address
     */
    // no need to call bind for client site
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port=htons(SERVPORT);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr.sin_zero), 8);

    if (-1 == connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct 
    sockaddr)))
    {
        perror("Connect failed!");
        exit(1);
    }
    std::cout << "Connected with remote site successfully." << std::endl;

    /* Receive traffic from server site.
     * Format: int recv(int sock_fd, void *buf, int len, unsigned int flags);
     * Return: succ/fail
     * Param : sock_fd from socket() return value
     *         flags = 0 usually
     */
    // you can also call send/receive here
    char buf[MAX_DATA_SIZE];
    int recv_bytes;
    if (-1 == (recv_bytes = recv(sock_fd, buf, MAX_DATA_SIZE, 0)))
    {
        perror("Receive failed!");
        exit(1);
    }
    buf[recv_bytes] = '\0';
    std::cout << buf << std::endl;

    // close socket
    close(sock_fd);
    
    return 0;
}
