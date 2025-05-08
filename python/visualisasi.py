# Visualisasi Regresi Linear dan Interpolasi Lagrange Kelompok 4

import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import lagrange
from sklearn.linear_model import LinearRegression

# Data yang ada
x_data = np.array([1, 2, 3, 4, 5])
y_data = np.array([1.1, 2.2, 3.1, 4.0, 5.1])

# Linear Regression (menggunakan sklearn)
model = LinearRegression()
model.fit(x_data.reshape(-1, 1), y_data)
y_pred_regression = model.predict(x_data.reshape(-1, 1))

# Lagrange Interpolation
poly = lagrange(x_data, y_data)
y_pred_lagrange = poly(x_data)

# Visualisasi data
plt.figure(figsize=(8, 6))

# Plot Data Points
plt.scatter(x_data, y_data, color='blue', label='Data Asli')

# Plot Linear Regression Line
plt.plot(x_data, y_pred_regression, color='green', label='Regresi Linear')

# Plot Prediksi Lagrange (Interpolasi)
plt.plot(x_data, y_pred_lagrange, color='red', label='Prediksi Lagrange')

# Menambahkan title, labels dan legenda
plt.title('Visualisasi Regresi Linear dan Interpolasi Lagrange')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()

# Menampilkan plot
plt.grid(True)
plt.show()
