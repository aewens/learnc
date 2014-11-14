#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    
    if(argc == 1) {
        printf("No, stop that\n");
    } else if (argc > 1 && argc < 5) {
        for(i = 1; i < argc; i++) {
            printf("%d. %s\n", i, argv[i]);
        }
        printf("\n");
    } else {
        printf("No, stop that\n");
    }
    
    return 0;
}
