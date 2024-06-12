#ifndef LIST_H
#define LIST_H

#include "entity.h"

// Структура для зберігання динамічного масиву аудиторій
typedef struct {
    Audience *array;
    int size;
    int capacity;
} AudienceList;

void initList(AudienceList *list);
void addAudience(AudienceList *list, Audience audience);
void printList(const AudienceList *list);
void findLargeAudiences(const AudienceList *list, int minCapacity);
void removeAudience(AudienceList *list, int index);
void sortList(AudienceList *list, int (*compare)(const void *, const void *));

#endif // LIST_H
