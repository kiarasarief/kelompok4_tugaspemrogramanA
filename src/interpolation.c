#include <stdio.h>

// Fungsi untuk Lagrange Interpolation
double lagrange_interpolation(int years[], double data[], int n, int year_pred) {
    double result = 0;
    
    for (int i = 0; i < n; i++) {
        double term = data[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term = term * (year_pred - years[j]) / (years[i] - years[j]);
            }
        }
        result += term;
    }

    return result;
}
