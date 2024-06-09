#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Перевірка кількості аргументів
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    // Відкриття вхідного файлу для читання
    FILE *file = fopen(input_file, "r");
    if (!file) {
        perror("Неможливо відкрити вхідний файл");
        return EXIT_FAILURE;
    }

    int height, base_width;
    char fill_char;

    // Читання параметрів трикутника з файлу
    if (fscanf(file, "%d %d %c", &height, &base_width, &fill_char) != 3) {
        fprintf(stderr, "Невірний формат вхідного файлу\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Закриття вхідного файлу
    fclose(file);

    // Функція для створення трикутника
    create_triangle(height, base_width, fill_char, output_file);

    return EXIT_SUCCESS;
}
