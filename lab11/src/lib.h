#ifndef LIB_H
#define LIB_H

#define ROWS 3
#define COLS 3

// Прототипи функцій
void inputMatrix(float matrix[ROWS][COLS], const char *name);
void printMatrix(float matrix[ROWS][COLS]);
void addMatrices(float result[ROWS][COLS], float matrix1[ROWS][COLS], float matrix2[ROWS][COLS]);

#endif /* LIB_H */
