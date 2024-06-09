#include <stdio.h>
#include <string.h>
#include <unistd.h> // Для функцій write() та read()
#include "lib.h"

// Функція для введення елементів матриці
void inputMatrix(float matrix[ROWS][COLS], const char *name) {
    write(1, "Введіть елементи матриці ", strlen("Введіть елементи матриці "));
    write(1, name, strlen(name));
    write(1, ":\n", strlen(":\n"));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            char prompt[50];
            sprintf(prompt, "Елемент [%d][%d]: ", i + 1, j + 1);
            char input[20];
            read(0, input, sizeof(input));
            sscanf(input, "%f", &matrix[i][j]);
        }
    }
}

// Функція для виведення матриці
void printMatrix(float matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        char row[100] = {0};
        for (int j = 0; j < COLS; ++j) {
            char temp[20];
            sprintf(temp, "%.2f ", matrix[i][j]);
            strcat(row, temp);
        }
        strcat(row, "\n");
        write(1, row, strlen(row));
    }
}

// Функція для додавання двох матриць
void addMatrices(float result[ROWS][COLS], float matrix1[ROWS][COLS], float matrix2[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
