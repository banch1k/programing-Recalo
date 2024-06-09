#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

void create_triangle(int height, int base_width, char fill_char, const char *output_file) {
    FILE *file = fopen(output_file, "w");
    if (!file) {
        perror("Неможливо відкрити вихідний файл");
        exit(EXIT_FAILURE);
    }

// Генерація рівнобедреного трикутника із заданих символів і запис його у файл.
    int midpoint = base_width / 2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < base_width; j++) {
            if (j >= (midpoint - i) && j <= (midpoint + i)) {
                fprintf(file, "%c ", fill_char);
            } else {
                fprintf(file, "  ");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
