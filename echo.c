#include <stdio.h>
#include <stdlib.h>

int echo_main(int argc, char *argv[]) {
    
    if (argc == 1)
    {
        printf("\n");
        exit(0);
    }
    
    int i = 1;
    while (argv[i] != NULL)
    {
        printf("%s", argv[i]);
        if (i < argc - 1){
            printf(" ");
        }
        
        i++;
    }
    
    printf("\n");
    return 0 ;
}
