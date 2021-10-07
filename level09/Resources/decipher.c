#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <memory.h>
#include <ctype.h>

int main(int ac, char **av)
{
	char buff[512];
	bzero(buff, 512);
	if (ac != 2)
		exit(-1);
	int fd = open(av[1], O_RDONLY);
	if (!fd)
		exit(-1);
	size_t size = read(fd, &buff, 512);
	for(int i = 0; i<size; i++)
		if (!isspace(buff[i]))
			buff[i] = buff[i] - (char)i;
	puts(buff);
	return(0);
}
