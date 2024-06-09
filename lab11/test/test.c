#include <stdio.h>
#include <math.h> // Включення math.h для функції fabs.
#include "lib.h"

// Визначення значення допустимої похибки для порівняння чисел з рухомою комою.
#define TOLERANCE 0.001

// Визначення функції для порівняння двох матриць з допустимою похибкою.
int compareMatrices(float result[ROWS][COLS], float expected[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Порівняння кожного елементу з використанням допустимої похибки.
            if (fabs(result[i][j] - expected[i][j]) > TOLERANCE) {
                return 0; // Повернення 0, якщо матриці не рівні.
            }
        }
    }
    return 1; // Повернення 1, якщо матриці рівні з урахуванням допустимої похибки.
}

int main() {
    // Визначення матриці.
    float result[ROWS][COLS] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };

    float expected[ROWS][COLS] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };

    // Порівняння матриць з використанням допустимої похибки.
    if (compareMatrices(result, expected)) {
        printf("Матриці рівні з урахуванням допустимої похибки.\n");
    } else {
        printf("Матриці не рівні з урахуванням допустимої похибки.\n");
    }

    return 0;
}
