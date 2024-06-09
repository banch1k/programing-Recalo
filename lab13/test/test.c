#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");

    // Перевірка відкриття файлів
    if (!f1 || !f2) {
        perror("Неможливо відкрити файл для порівняння");
        exit(EXIT_FAILURE);
    }

    char line1[256], line2[256];

    // Порівняння рядків файлів
    while (fgets(line1, sizeof(line1), f1) && fgets(line2, sizeof(line2), f2)) {
        if (strcmp(line1, line2) != 0) {
            fprintf(stderr, "Файли %s та %s різняться\n", file1, file2);
            fclose(f1);
            fclose(f2);
            exit(EXIT_FAILURE);
        }
    }

    // Закриття файлів
    fclose(f1);
    fclose(f2);
}

void test_create_triangle() {
    const char *output_file = "assets/test_output.txt";
    const char *expected_file = "assets/testexpected_output.txt";

    // Створення файлу з очікуваним результатом
    FILE *expected = fopen(expected_file, "w");
    if (!expected) {
        perror("Неможливо відкрити файл очікуваного результату");
        exit(EXIT_FAILURE);
    }

    // Запис очікуваного результату у файл
    fprintf(expected,
        "      *       \n"
        "    * * *     \n"
        "  * * * * *   \n"
        "* * * * * * * \n"
    );
    fclose(expected);

    // Виклик функції create_triangle для генерації трикутника
    create_triangle(4, 7, '*', output_file);

    // Порівняння результатів
    compare_files(output_file, expected_file);

    // Якщо файли однакові, тест пройдено
    printf("Тест пройдено\n");
}

int main() {
    test_create_triangle();
    return 0;
}
