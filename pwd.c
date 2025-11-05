#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define COUNT 1000 
int pwd_main() {
    
     char buf[COUNT]; 
     getcwd(buf, COUNT);
     write(1, buf, COUNT);

    return 0;
}
