#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define STD_RANGE 255
#define STD_COLS 512
#define STD_ROWS 512

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

/* Saves a monocromatic .tga image file */
int save_image(char *name, int cols, int rows, int m[cols][rows]) {
    FILE *fp;
    char path[sizeof(name)+4];
    strcpy(path, name);
    strcat(path, ".tga");
    if ((fp = fopen(path, "w")) == NULL) {
        fprintf(stderr, "Couldn't open image file %s\n", path);
        return 1;
    }
    printf("Opened image file at %s\n", path);

    /* Header */
    unsigned char header[18];
    header[0] = 0x00; // ID length
    header[1] = 0x00; // Color map type
    header[2] = 0x03; // Image type
    header[3] = 0x00; header[4] = 0x00; // X origin
    header[5] = 0x00; header[6] = 0x00; // Y origin
    // Color map is not relevant
    memcpy(header+12, &cols, 2); // Image width
    memcpy(header+14, &rows, 2); // Image height
    header[16] = 0x08; // Pixel depth (in bits)
    header[17] = 0x00; // Image descriptor

    fwrite(header, sizeof(header), 1, fp);
    printf("Wrote header\n");

    /* Image data */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fputc(m[j][i], fp);
        }
    }
    printf("Wrote image data\n");

    printf("Finished writing\n");

    if (fclose(fp) == EOF) {
        fprintf(stderr, "Couldn't close image file\n");
        return 2;
    }
    printf("Closed image file\n");
    return 0;
}

/* First argument is the range and the second and third 
 * are the number of collumns and rows of the matrix */
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Use current time *in seconds* as seed
    
    int rows = (argc > 3) ? atoi(argv[3]) : STD_ROWS; // Matrix rows
    int cols = (argc > 2) ? atoi(argv[2]) : STD_COLS; // Matrix collumns
    int range = (argc > 1) ? atoi(argv[1]) : STD_RANGE; // Range of random number
    assert(range > 0 && rows > 0 && cols > 0);

    int m[cols][rows];
    random_matrix(range, cols, rows, m);

    printf("Your lucky numbers are\n");
    print_matrix(cols, rows, m);

    return save_image("image", cols, rows, m);
}
