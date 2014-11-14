#include <stdio.h>

int main(int argc, char *argv[])
{
    int nums[4] = {0};
    char name[4] = {'a'};
    
    printf("Nums: %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
    printf("Name: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
    printf("Name: %s\n", name);
    
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 4;
    nums[3] = 8;
    
    name[0] = 'C';
    name[1] = 'a';
    name[2] = 't';
    name[3] = '\0';
    
    printf("Nums: %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
    printf("Name: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
    printf("Name: %s\n", name);
    
    char *austin = "Austin";
    printf("My name is: %s\n", austin);
    printf("Name: %c %c %c %c %c %c %c\n", austin[0], austin[1], austin[2], 
                                austin[3], austin[4], austin[5], austin[6]);
    
    return 0;
}
