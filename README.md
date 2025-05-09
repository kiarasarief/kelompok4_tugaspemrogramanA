# Tugas Pemrograman A - Komputasi Numerik Kelompok 4

Proyek ini adalah implementasi dari regresi linear dan interpolasi menggunakan metode Lagrange, dengan program yang ditulis dalam bahasa C. Data yang hilang pada file CSV akan diprediksi menggunakan metode regresi dan interpolasi.

## Struktur Folder

- /data: File CSV contoh
- /src: Kode sumber program C
- /include: Header untuk fungsi-fungsi
- /laporan: Draft laporan tugas

## Cara Menjalankan

1. Compile dengan `cd src` dan jalankan dengan `gcc -I "../include" main.c regression.c interpolation.c utils.c -o program_fixed.exe`
2. Jalankan dengan `.\program_fixed.exe`
