#ifndef UTILS_H
#define UTILS_H

void read_csv(const char *filename, int *years, double *population, double *internet_usage, int *size);
double predict(double m, double c, int year);  // Deklarasi fungsi predict

#endif
