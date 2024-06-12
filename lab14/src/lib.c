#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функція для читання даних про аудиторії з файлу
void read_audiences(const char* filename, Audience** audiences, int* count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Не вдається відкрити файл");
        exit(1);
    }

    fscanf(file, "%d", count);
    *audiences = (Audience*)malloc(sizeof(Audience) * (size_t)(*count));
    for (int i = 0; i < *count; ++i) {
        fscanf(file, "%d %s %d %d %d %s %s %d %s %d", 
            &(*audiences)[i].occupied, 
            (*audiences)[i].name, 
            &(*audiences)[i].capacity, 
            &(*audiences)[i].location.building, 
            &(*audiences)[i].location.floor, 
            (*audiences)[i].condition,
            (*audiences)[i].has_projector,
            &(*audiences)[i].board_count,
            (*audiences)[i].has_lab_assistant,
            &(*audiences)[i].computer_count);
    }

    fclose(file);
}

// Функція для запису даних про аудиторії у файл
void write_audiences(const char* filename, Audience* audiences, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Не вдається відкрити файл");
        exit(1);
    }

    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%d %s %d %d %d %s %s %d %s %d\n",
            audiences[i].occupied,
            audiences[i].name,
            audiences[i].capacity,
            audiences[i].location.building,
            audiences[i].location.floor,
            audiences[i].condition,
            audiences[i].has_projector,
            audiences[i].board_count,
            audiences[i].has_lab_assistant,
            audiences[i].computer_count);
    }

    fclose(file);
}

// Функція для виведення даних про аудиторії на екран
void print_audiences(Audience* audiences, int count) {
    for (int i = 0; i < count; ++i) {
        printf("Зайнятість: %s, Назва: %s, Вмістимість: %d, Розташування: %d-%d, Стан: %s, Проектор: %s, Кількість дошок: %d, Кількість комп'ютерів: %d, Лаборант: %s\n",
            audiences[i].occupied ? "так" : "ні",
            audiences[i].name,
            audiences[i].capacity,
            audiences[i].location.building,
            audiences[i].location.floor,
            audiences[i].condition,
            audiences[i].has_projector,
            audiences[i].board_count,
            audiences[i].computer_count,
            audiences[i].has_lab_assistant);
    }
}

// Функція для знаходження аудиторій, що вміщують більше 150 осіб
Audience* find_large_audiences(Audience* audiences, int count, int* result_count) {
    *result_count = 0;
    for (int i = 0; i < count; ++i) {
        if (audiences[i].capacity > 150) {
            (*result_count)++;
        }
    }

    Audience* large_audiences = (Audience*)malloc(sizeof(Audience) * (size_t)(*result_count));
    int index = 0;
    for (int i = 0; i < count; ++i) {
        if (audiences[i].capacity > 150) {
            large_audiences[index++] = audiences[i];
        }
    }

    return large_audiences;
}

// Функція для сортування масиву аудиторій за заданим критерієм
void sort_audiences(Audience* audiences, int count, int (*compare)(const Audience*, const Audience*)) {
    qsort(audiences, (size_t)count, sizeof(Audience), (int (*)(const void*, const void*))compare);
}
