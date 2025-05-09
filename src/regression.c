#include <stdio.h>

// Fungsi regresi linear (Least Square)
void linear_regression(int years[], double data[], int n, double *m, double *c) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;

    // Perhitungan untuk m (gradien) dan c (intersep)
    for (int i = 0; i < n; i++) {
        sum_x += years[i];
        sum_y += data[i];
        sum_xy += years[i] * data[i];
        sum_xx += years[i] * years[i];
    }

    *m = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    *c = (sum_y - (*m) * sum_x) / n;
}
