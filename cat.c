#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define COUNT 100 
int main(int argc, char* argv[])
{
	char buf[COUNT];

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(-1);
	}
	int fd = open(argv[1],O_RDONLY);
	if (fd < 0 )
	{
		printf("Could not open the file\n");
		exit(-2);
	}
	int num_read;
	while((num_read = read (fd, buf, COUNT)) > 0)
	{
		if (write(1,buf, num_read) < 0)
		{
			printf("Write Failed\n");
			exit(-3);
		}
	}

	close(fd);
	return 0;


}
