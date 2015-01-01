#ifndef _fifteen_h
#define _fifteen_h

// make THE_SIZE in fifteen.c available to other .c files
extern int THE_SIZE;

// get/set internal static variables
int get_age();
void set_age(int age);

// updates a static variable that is inside update_ratio
double update_ratio(double new_ratio);

void print_size();

#endif
