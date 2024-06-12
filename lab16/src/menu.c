#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

// Декларація функції порівняння
int compareByCapacity(const void *a, const void *b);

void displayMenu() {
    printf("Меню:\n");
    printf("1. Вивід списку\n");
    printf("2. Додати аудиторію\n");
    printf("3. Знайти великі аудиторії\n");
    printf("4. Видалити аудиторію\n");
    printf("5. Сортувати список\n");
    printf("6. Зчитати дані з файлу\n");
    printf("7. Записати дані у файл\n");
    printf("8. Вихід\n");
}

void handleMenu(AudienceList *list) {
    int choice;
    while (1) {
        displayMenu();
        printf("Виберіть опцію: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printList(list);
                break;
            case 2: {
                Audience audience;
                printf("Введіть назву аудиторії: ");
                scanf("%49s", audience.name);
                printf("Введіть вмістимість аудиторії: ");
                scanf("%d", &audience.capacity);
                addAudience(list, audience);
                break;
            }
            case 3:
                findLargeAudiences(list, 150);
                break;
            case 4: {
                int index;
                printf("Введіть індекс для видалення: ");
                scanf("%d", &index);
                removeAudience(list, index);
                break;
            }
            case 5:
                sortList(list, compareByCapacity);
                break;
            case 6: {
                char filename[100];
                printf("Введіть ім'я файлу: ");
                scanf("%99s", filename);
                readFromFile(list, filename);
                break;
            }
            case 7: {
                char filename[100];
                printf("Введіть ім'я файлу: ");
                scanf("%99s", filename);
                writeToFile(list, filename);
                break;
            }
            case 8:
                return;
            default:
                printf("Неправильний вибір, спробуйте ще раз.\n");
        }
    }
}

