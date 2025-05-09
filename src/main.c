#include <stdio.h>
#include "regression.h"
#include "interpolation.h"
#include "utils.h"

int main() {
    int years[64];        // Array untuk menyimpan tahun (int[])
    double population[64];  // Array untuk populasi (double[])
    double internet_usage[64];  // Array untuk persentase internet (double[])
    int size;

    // Membaca data dari CSV
    read_csv("c:\\College\\4th Semester\\komnum\\kelompok4_tugaspemrograman_a\\src\\Data-Tugas-Pemrograman-A.csv", years, population, internet_usage, &size);

    // Debugging: Memastikan data yang dibaca
    printf("\nData yang dibaca:\n");
    for (int i = 0; i < size; i++) {
        printf("Tahun: %d, Populasi: %.2f, Pengguna Internet: %.2f\n", years[i], population[i], internet_usage[i]);
    }

    // Menghitung regresi linear untuk populasi dan persentase internet
    double m_population, c_population, m_internet, c_internet;
    
    // Regresi linear untuk populasi
    linear_regression(years, population, size, &m_population, &c_population);
    // Regresi linear untuk persentase internet
    linear_regression(years, internet_usage, size, &m_internet, &c_internet);

    // Debugging: Memastikan hasil regresi
    printf("\nHasil regresi:\n");
    printf("Regresi Populasi: m = %.2f, c = %.2f\n", m_population, c_population);
    printf("Regresi Internet: m = %.2f, c = %.2f\n", m_internet, c_internet);

    // Mengisi data yang hilang (misalnya di tahun 2005, 2006, 2015, 2016) dengan regresi
    double pop_2005 = predict(m_population, c_population, 2005);
    double pop_2006 = predict(m_population, c_population, 2006);
    double pop_2015 = predict(m_population, c_population, 2015);
    double pop_2016 = predict(m_population, c_population, 2016);

    double internet_2005 = predict(m_internet, c_internet, 2005);
    double internet_2006 = predict(m_internet, c_internet, 2006);
    double internet_2015 = predict(m_internet, c_internet, 2015);
    double internet_2016 = predict(m_internet, c_internet, 2016);

    // Menampilkan hasil regresi untuk data yang hilang
    printf("\nPerkiraan Jumlah Penduduk di Tahun 2005: %.2f juta\n", pop_2005);
    printf("Perkiraan Jumlah Penduduk di Tahun 2006: %.2f juta\n", pop_2006);
    printf("Perkiraan Jumlah Penduduk di Tahun 2015: %.2f juta\n", pop_2015);
    printf("Perkiraan Jumlah Penduduk di Tahun 2016: %.2f juta\n", pop_2016);

    printf("Perkiraan Persentase Pengguna Internet di Tahun 2005: %.2f%%\n", internet_2005);
    printf("Perkiraan Persentase Pengguna Internet di Tahun 2006: %.2f%%\n", internet_2006);
    printf("Perkiraan Persentase Pengguna Internet di Tahun 2015: %.2f%%\n", internet_2015);
    printf("Perkiraan Persentase Pengguna Internet di Tahun 2016: %.2f%%\n", internet_2016);

    // Formulasikan persamaan polinomial untuk persentase internet dan populasi
    printf("\nPersamaan Polinomial untuk Persentase Pengguna Internet: y = %.2fx + %.2f\n", m_internet, c_internet);
    printf("Persamaan Polinomial untuk Pertumbuhan Populasi: y = %.2fx + %.2f\n", m_population, c_population);

    // Estimasi untuk tahun 2030 dan 2035
    double pop_2030 = predict(m_population, c_population, 2030);
    double internet_2035 = predict(m_internet, c_internet, 2035);
    
    printf("\nEstimasi Jumlah Populasi di Tahun 2030: %.2f juta\n", pop_2030);
    printf("Estimasi Persentase Pengguna Internet di Tahun 2035: %.2f%%\n", internet_2035);

    return 0;
}
