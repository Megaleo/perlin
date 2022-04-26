#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#define STD_RANGE 10
#define STD_COLS 10
#define STD_ROWS 10

/* Generate a random matrix with integers from 0 to range-1
 * store it in m */
void random_matrix(int range, int cols, int rows, int m[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[j][i] = rand() % range; // Almost uniform between 0 and range-1
        }
    }
}

void print_matrix(int cols, int rows, int m[cols][rows]) {    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d, ", m[j][i]);
        }
        printf("\n");
    }
    printf("\b\b \b\n"); // Erases last ", "
}

/* First argument is the range and the second and third 
 * are the number of collumns and rows of the matrix */
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Use current time *in seconds* as seed
    
    int rows = (argc > 3) ? atoi(argv[3]) : STD_ROWS; // Matrix rows
    int cols = (argc > 2) ? atoi(argv[2]) : STD_COLS; // Matrix collumns
    int range = (argc > 1) ? atoi(argv[1]) : STD_RANGE; // Range of random number
    assert(range > 0 && rows > 1 && cols > 1);

    int m[cols][rows];
    random_matrix(range, cols, rows, m);

    printf("Your lucky numbers are\n");
    print_matrix(cols, rows, m);
}
