#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    
    printf("Filename: %s\n", argv[0]);
    i++;
    
    while(i < argc) {
        printf("%d. %s\n", i, argv[i]);
        i++;
    }
    printf("\n");
    
    char *names[] = {"Austin","Bob","Joe","Louis"};
    int names_num = sizeof(names) / 8;
    
    i = 0;
    while(i < names_num) {
        printf("%d. %s\n", i, names[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}
