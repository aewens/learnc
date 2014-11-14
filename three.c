#include <stdio.h>

int main(int argc, char *argv[])
{
    int nums[] = {1,2,3,4,5};
    char first[] = "Austin";
    char last[] = {'E','w','e','n','s','\0'};
    
    printf("Size of ints: %ld\n", sizeof(int));
    printf("Size of nums: %ld\n", sizeof(nums));
    printf("Ints in nums: %ld\n", sizeof(nums) / sizeof(int));
    printf("First: %d, Second: %d\n", nums[0], nums[1]);
    printf("Size of chars: %ld\n", sizeof(char));
    printf("Size of first: %ld\n", sizeof(first));
    printf("Chars in first: %ld\n", sizeof(first) / sizeof(char));
    printf("Size of last: %ld\n", sizeof(last));
    printf("Chars in last: %ld\n", sizeof(last) / sizeof(char));
    printf("First: \"%s\", Last: \"%s\"\n", first, last);
    
    return 0;
}
