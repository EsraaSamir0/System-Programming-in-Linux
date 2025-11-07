#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 15000
int femtoshell_main(int argc, char *argv[]) {
    char buf[SIZE];
    char prompt[] = "EsraaShell>";
    int num_read, status;
    
    while (1)
    {
        if (write(1, prompt, strlen(prompt)) < 0)
        { 
            printf("ERROR : Write Failed \n");
            exit(-1);
        }
    
        if (fgets(buf, SIZE, stdin) == NULL)
         break;
         
         // Remove trailing newline 
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n')
         buf[len - 1] = '\0';

            
        if (buf[0] == '\n'){
            status = 0;
            continue;
        }
        
        if (strcmp(buf, "exit") == 0)
        {
            write(1, "Good Bye\n", 9);
            status = 0;
            break;
        }
        
        else if (strncmp(buf, "echo ", 5) == 0)
        {
            // Print whatever comes after "echo "
            if (write(1, buf + 5, strlen(buf + 5)) < 0)
            {
                printf("write");
                exit(-3);
            }
            write(1, "\n", 1); 
             status = 0;
        }
    // If command is exactly "echo" with no text
        else if (strcmp(buf, "echo") == 0)
        {
            write(1, "\n", 1);
            status = 0;
        }
        else if (strcmp(buf, "") == 0)
        {
            status = 0;
        }
        // Invalid command
        else
        {
            write(1, "Invalid command\n", 16);
            status = 1;
        }
    }
return status;

}
