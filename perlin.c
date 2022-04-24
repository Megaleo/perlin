#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#define DEFAULT_RANGE 10
#define DEFAULT_ARRAYSIZE 10

/* First argument is the range and the second is the array size */
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Use current time *in seconds* as seed
    int as = (argc > 2) ? atoi(argv[2]) : DEFAULT_ARRAYSIZE; // Array size
    assert(as > 1);
    int r = (argc > 1) ? atoi(argv[1]) : DEFAULT_RANGE; // Range of random number
    assert(r > 0);
    int ns[as];
    printf("Your lucky numbers are ");
    for (int i = 0; i < as; i++) {
        ns[i] = rand() % r; // Almost uniform between 0 and r-1
        printf("%d, ", ns[i]);
    }
    printf("\b\b \b\n"); // Erases last ", "
}
