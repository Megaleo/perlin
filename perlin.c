#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#define STD_RANGE 10
#define STD_COLS 10
#define STD_ROWS 10

/* First argument is the range and the second and third 
 * are the number of collumns and rows of the array */
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Use current time *in seconds* as seed
    
    int ar = (argc > 3) ? atoi(argv[3]) : STD_ROWS; // Array rows
    int ac = (argc > 2) ? atoi(argv[2]) : STD_COLS; // Array collumns
    int r = (argc > 1) ? atoi(argv[1]) : STD_RANGE; // Range of random number
    assert(r > 0 && ar > 1 && ac > 1);
    
    int ns[ac][ar];
    printf("Your lucky numbers are\n");
    for (int i = 0; i < ar; i++) {
        for (int j = 0; j < ac; j++) {
            ns[j][i] = rand() % r; // Almost uniform between 0 and r-1
            printf("%d, ", ns[j][i]);
        }
        printf("\n");
    }
    printf("\b\b \b\n"); // Erases last ", "
}
