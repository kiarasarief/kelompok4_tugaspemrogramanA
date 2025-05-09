#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk membaca file CSV
void read_csv(const char *filename, int *years, double *population, double *internet_usage, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File tidak ditemukan: %s\n", filename);
        return;
    }

    // Skip the header line
    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    
    int i = 0;
    int year;
    double internet, pop;
    while (fscanf(file, "%d,%lf,%lf\n", &year, &internet, &pop) == 3) {
        years[i] = year;
        internet_usage[i] = internet;
        population[i] = pop;
        i++;
    }
    *size = i;
    fclose(file);
    printf("Read %d rows from CSV file\n", i);
}

// Fungsi untuk memprediksi data yang hilang menggunakan regresi linear
double predict(double m, double c, int year) {
    return m * year + c;  // Menggunakan persamaan y = mx + c
}
