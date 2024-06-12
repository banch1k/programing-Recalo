#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ініціалізація списку
void initList(AudienceList *list) {
    list->head = NULL;
}

// Додавання аудиторії в кінець списку
void addAudience(AudienceList *list, Audience audience) {
    AudienceNode *newNode = malloc(sizeof(AudienceNode));
    newNode->data = audience;
    newNode->next = NULL;

    if (!list->head) {
        list->head = newNode;
    } else {
        AudienceNode *temp = list->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Вивід списку на екран
void printList(const AudienceList *list) {
    AudienceNode *temp = list->head;
    int index = 0;
    while (temp) {
        printf("%d. Номер аудиторії: %s, Вмістимість: %d\n", index, temp->data.name, temp->data.capacity);
        temp = temp->next;
        index++;
    }
}

// Пошук аудиторій, що вміщують більше 150 осіб
void findLargeAudiences(const AudienceList *list, int minCapacity) {
    AudienceNode *temp = list->head;
    while (temp) {
        if (temp->data.capacity > minCapacity) {
            printf("Номер аудиторії: %s, Вмістимість: %d\n", temp->data.name, temp->data.capacity);
        }
        temp = temp->next;
    }
}

// Видалення аудиторії за індексом
void removeAudience(AudienceList *list, int index) {
    if (!list->head) return;
    AudienceNode *temp = list->head;

    if (index == 0) {
        list->head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) return;

    AudienceNode *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Функція для порівняння двох аудиторій за вмістимістю
int compareByCapacity(const void *a, const void *b) {
    return ((Audience *)a)->capacity - ((Audience *)b)->capacity;
}

// Сортування списку за заданим критерієм
void sortList(AudienceList *list, int (*compare)(const void *, const void *)) {
    if (!list->head) return;

    // Розрахунок розміру списку
    size_t size = 0;
    AudienceNode *temp = list->head;
    while (temp) {
        size++;
        temp = temp->next;
    }

    // Копіювання елементів списку в масив
    Audience *array = malloc(size * sizeof(Audience));
    temp = list->head;
    for (size_t i = 0; i < size; i++) {
        array[i] = temp->data;
        temp = temp->next;
    }

    // Сортування масиву
    qsort(array, size, sizeof(Audience), compare);

    // Копіювання відсортованих елементів
    temp = list->head;
    for (size_t i = 0; i < size; i++) {
        temp->data = array[i];
        temp = temp->next;
    }

    free(array);
}

// Читання даних
void readFromFile(AudienceList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Не вдалося відкрити файл для читання");
        return;
    }

    Audience audience;
    while (fscanf(file, "%49s%d", audience.name, &audience.capacity) == 2) {
        addAudience(list, audience);
    }

    fclose(file);
}

// Запис даних
void writeToFile(const AudienceList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Не вдалося відкрити файл для запису");
        return;
    }

    AudienceNode *temp = list->head;
    while (temp) {
        fprintf(file, "%s %d\n", temp->data.name, temp->data.capacity);
        temp = temp->next;
    }

    fclose(file);
}
