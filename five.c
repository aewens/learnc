#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    
    printf("Filename: %s\n", argv[0]);
    
    for(i = 1; i < argc; i++) {
        printf("%d. %s\n", i, argv[i]);
    }
    printf("\n");
    
    char *names[] = {"Austin","Bob","Joe","Louis"};
    int names_num = sizeof(names) / 8;
    
    for(i = 0; i < names_num; i++) {
        printf("%d. %s\n", i, names[i]);
    }
    printf("\n");
    
    return 0;
}
