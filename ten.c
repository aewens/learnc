#include <stdio.h>

int main(int argc, char *argv[])
{
    int nums[] = {1,2,3,4,5};
    char *names[] = {
        "Andrew", "Bill", 
        "Charles", "Damin", "Evan"
    };
    
    int count = sizeof(nums) / sizeof(int);
    int i = 0;
    
    for(i = 0; i < count; i++) {
        printf("%s is %d/5 awesome.\n", names[i], nums[i]);
    }
    
    printf("---\n");
    
    int *cur_num = nums;
    char **cur_name = names;
    
    for(i = 0; i < count; i++) {
        printf("%s is %d/5 cool.\n", *(cur_name+i), *(cur_num+i));
    }
    
    printf("---\n");
    
    for(i = 0; i < count; i++) {
        printf("%s is %d/5 amazing.\n", cur_name[i], cur_num[i]);
    }
    
    printf("---\n");
    
    for(cur_num = nums, cur_name = names;
        (cur_num - nums) < count;
        cur_num++, cur_name++) {
        printf("%s is %d/5.\n", *cur_name, *cur_num);
    }
    
    return 0;
}
