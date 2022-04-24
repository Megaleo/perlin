#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DEFAULT_RANGE 10

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Use current time as seed
    int r = (argc > 1) ? atoi(argv[1]) : DEFAULT_RANGE; // Range of random number
    int n = rand() % r; // Almost uniform between 0 and r-1  
    printf("Your lucky number is %d\n", n);
}
