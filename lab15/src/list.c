#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ініціалізація списку
void initList(AudienceList *list) {
    list->size = 0;
    list->capacity = 10;
    list->array = malloc((size_t)list->capacity * sizeof(Audience));
}

// Додавання аудиторії
void addAudience(AudienceList *list, Audience audience) {
    if ((size_t)list->size >= (size_t)list->capacity) {
        list->capacity *= 2;
        list->array = realloc(list->array, (size_t)list->capacity * sizeof(Audience));
    }
    list->array[list->size++] = audience;
}

// Вивід списку на екран
void printList(const AudienceList *list) {
    for (size_t i = 0; i < (size_t)list->size; i++) {
        printf("Номер аудиторії: %s, Вмістимість: %d\n", list->array[i].name, list->array[i].capacity);
    }
}

// Пошук аудиторій, що вміщують більше 150 осіб
void findLargeAudiences(const AudienceList *list, int minCapacity) {
    for (size_t i = 0; i < (size_t)list->size; i++) {
        if (list->array[i].capacity > minCapacity) {
            printf("Номер аудиторії: %s, Вмістимість: %d\n", list->array[i].name, list->array[i].capacity);
        }
    }
}

// Видалення аудиторії за індексом
void removeAudience(AudienceList *list, int index) {
    if (index >= 0 && index < list->size) {
        memmove(&list->array[index], &list->array[index + 1], ((size_t)list->size - (size_t)index - 1) * sizeof(Audience));
        list->size--;
    }
}

// Сортування списку за заданим критерієм
void sortList(AudienceList *list, int (*compare)(const void *, const void *)) {
    qsort(list->array, (size_t)list->size, sizeof(Audience), compare);
}
