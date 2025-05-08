
#include <stdio.h>

double lagrange_interpolation(double x[], double y[], int n, double x_pred) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term = term * (x_pred - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}
