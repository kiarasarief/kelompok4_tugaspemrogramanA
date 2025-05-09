#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk membaca file CSV
void read_csv(const char *filename, int *years, double *population, double *internet_usage, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File tidak ditemukan\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%d,%lf,%lf\n", &years[i], &population[i], &internet_usage[i]) != EOF) {
        i++;
    }
    *size = i;
    fclose(file);
}

// Fungsi untuk memprediksi data yang hilang menggunakan regresi linear
double predict(double m, double c, int year) {
    return m * year + c;  // Menggunakan persamaan y = mx + c
}
