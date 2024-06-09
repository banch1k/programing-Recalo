#include <unistd.h> // Для функції write()
#include <string.h> // Для функції strlen()
#include "lib.h"

int main() {
    // Визначення матриць та задання їх значень
    float matrix1[ROWS][COLS] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };

    float matrix2[ROWS][COLS] = {
        {9.0f, 8.0f, 7.0f},
        {6.0f, 5.0f, 4.0f},
        {3.0f, 2.0f, 1.0f}
    };

    float result[ROWS][COLS];

    // Додавання матриць
    addMatrices(result, matrix1, matrix2);

    // Вивід результату
    write(1, "Результат додавання матриць:\n", strlen("Результат додавання матриць:\n"));
    printMatrix(result);

    return 0;
}
