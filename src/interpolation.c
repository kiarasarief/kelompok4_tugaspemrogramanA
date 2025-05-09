#include <stdio.h>

// Fungsi untuk Lagrange Interpolation
double lagrange_interpolation(int years[], double data[], int n, int year_pred) {
    double result = 0;
    
    // Precompute denominators for all terms
    double denominators[n];
    for (int i = 0; i < n; i++) {
        denominators[i] = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                denominators[i] *= (years[i] - years[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        double term = data[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (year_pred - years[j]);
            }
        }
        result += term / denominators[i];
    }

    return result;
}
