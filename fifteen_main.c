#include "fifteen.h"
#include "dbg.h"

const char *MY_NAME = "Austin Ewens";

void scope_demo(int count)
{
    log_info("count is: %d", count);
    
    if(count > 10) {
        int count = 100; // bugs bunny
        log_info("count in this scope is %d", count);
    }
    
    log_info("count is at exit: %d", count);
    count = 3000;
    log_info("count after assign: %d", count);
}

int main(int argc, char *argv[])
{
    int age_now = get_age();
    log_info("My name: %s, Age: %d", MY_NAME, age_now);
    
    set_age(100);
    int new_age = get_age();
    log_info("In %d years I'll be: %d", new_age - age_now, new_age);
    
    log_info("THE_SIZE is: %d", THE_SIZE);
    print_size();
    
    THE_SIZE = 9;
    log_info("THE_SIZE is now: %d", THE_SIZE);
    print_size();
    
    log_info("Ratio @ 1: %f", update_ratio(2.0));
    log_info("Ratio @ 2: %f", update_ratio(10.0));
    log_info("Ratio @ 3: %f", update_ratio(300.0));
    
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);
    
    log_info("count after calling scope_demo: %d", count);
    
    return 0;
}
