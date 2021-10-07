#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6969
#define FAKE_TOKEN_PATH "/tmp/level10/token"
#define TOKEN_PATH "/home/user/level10/token"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	size_t read_bytes;
	int listenfd = 0, connfd = 0;
	struct sockaddr_in serv_addr;
	int addrlen = sizeof(serv_addr);

	bzero(buffer, BUFFER_SIZE);
	bzero(&serv_addr, sizeof(serv_addr));
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	if (bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)))
	{
		perror("Failed to bind server");
		exit(EXIT_FAILURE);
	}
	else
	{
		puts("Server started!");
	}

	if (listen(listenfd, 1))
	{
		perror("Failed to initialize listening queue");
		exit(EXIT_FAILURE);
	}
	{
		printf("Listening on %s on port %d\n", SERVER_IP, SERVER_PORT);
		fflush(stdout);
	}

	connfd = accept(listenfd, (struct sockaddr*)&serv_addr, (socklen_t*)&addrlen);

	if (remove(FAKE_TOKEN_PATH) || symlink(TOKEN_PATH, FAKE_TOKEN_PATH))
	{
		perror("Failed to create token link");
		exit(EXIT_FAILURE);
	}

	read_bytes = read(connfd, buffer, BUFFER_SIZE - 1);
	buffer[read_bytes] = '\0';
	printf("Initial message recieved: %s", buffer);
	fflush(stdout);
	read_bytes = read(connfd, buffer, BUFFER_SIZE - 1);
	buffer[read_bytes] = '\0';
	printf("Token recieved: %s", buffer);
	fflush(stdout);
	return(EXIT_SUCCESS);
}
