
#include <stdio.h>
#include <stdlib.h>

void read_csv(const char *filename, double *x_data, double *y_data, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File tidak ditemukan\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%lf,%lf\n", &x_data[i], &y_data[i]) != EOF) {
        i++;
    }
    *size = i;
    fclose(file);
}
