// Kode Lagrange Interpolasi dan Regresi Linear Kelompok 4

#include <stdio.h>
#include "regression.h"
#include "interpolation.h"
#include "utils.h"

int main() {
    double x_data[] = {1, 2, 3, 4, 5};
    double y_data[] = {1.1, 2.2, 3.1, 4.0, 5.1};

    double m, c;
    linear_regression(x_data, y_data, 5, &m, &c);
    printf("Linear Regression: y = %.2fx + %.2f\n", m, c);

    double x_missing = 2.5;
    double y_pred = lagrange_interpolation(x_data, y_data, 5, x_missing);
    printf("Prediksi Lagrange di x = %.2f: %.2f\n", x_missing, y_pred);

    return 0;
}
