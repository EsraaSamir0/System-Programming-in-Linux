#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define COUNT 100 
int cp_main(int argc, char *argv[]) {
    // Write your code here
    char buf[COUNT];
    
    if (argc != 3)
    {
        printf("Usage: %s filename destination\n", argv[0]);
		exit(-1);
    }
    
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0 )
    {
        printf(" %s file does not exist\n", argv[1]);
        exit(-2);
    }
    
    int fd2 = open(argv[2], O_RDWR | O_TRUNC);
    if (fd2 < 0 )
    {
        fd2 = open(argv[2], O_CREAT | O_WRONLY, 0644);
    }
    int num_read;
    while((num_read = read(fd1, buf, COUNT)) > 0)
    {
        if (write (fd2, buf, num_read) < 0 )
        {
            printf("Write Failed\n");
            exit(-3);
        }
    }
    
    close(fd1);
    close(fd2);
    return 0;

}
