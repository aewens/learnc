#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// typedef == fake type
typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *nums, int count, compare_cb cmp)
{
    int tmp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error");

    memcpy(target, nums, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                tmp = target[j+1];
                target[j+1] = target[j];
                target[j] = tmp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/** 
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *nums, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(nums, count, cmp);

    if(!sorted) die("Failed to sort as requested");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
}


int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: prog 3 1 2 4");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *nums = malloc(count * sizeof(int));
    if(!nums) die("Memory error");

    for(i = 0; i < count; i++) {
        nums[i] = atoi(inputs[i]);
    }

    test_sorting(nums, count, sorted_order);
    test_sorting(nums, count, reverse_order);
    test_sorting(nums, count, strange_order);

    free(nums);

    return 0;
}
