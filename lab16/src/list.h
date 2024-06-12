#ifndef LIST_H
#define LIST_H

#include "entity.h"

// Структура для зберігання вузла списку
typedef struct AudienceNode {
    Audience data;
    struct AudienceNode *next;
} AudienceNode;

// Структура для зберігання списку
typedef struct {
    AudienceNode *head;
} AudienceList;

void initList(AudienceList *list);
void addAudience(AudienceList *list, Audience audience);
void printList(const AudienceList *list);
void findLargeAudiences(const AudienceList *list, int minCapacity);
void removeAudience(AudienceList *list, int index);
void sortList(AudienceList *list, int (*compare)(const void *, const void *));
void readFromFile(AudienceList *list, const char *filename);
void writeToFile(const AudienceList *list, const char *filename);

#endif // LIST_H
