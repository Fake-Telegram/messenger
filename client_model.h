#ifndef NETWORK_H
#define NETWORK_H
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define MAX_BUF 1024

class Network {
    public:
        int socket_fd;

		Network();
		~Network();
		int send_message(const char *buffer, int buf_len);
        int get_message(char *buffer, int buf_len);
};

#endif NETWORK_H
