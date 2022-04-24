#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Use current time as seed
    int r = 10; // Range of the random number
    int n = rand() % r; // Almost uniform between 0 and r-1  
    printf("Your lucky number is %d\n", n);
}
