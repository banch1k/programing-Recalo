#include "list.h"
#include <stdio.h>
#include <stdlib.h> 

// Порівняння аудиторій за кількістю місць
int compareByCapacity(const void *a, const void *b) {
    return ((Audience *)a)->capacity - ((Audience *)b)->capacity;
}

void runMainTest() {
    AudienceList list;
    initList(&list);

    // Додавання даних
    addAudience(&list, (Audience){"Аудиторія 1", 50});
    addAudience(&list, (Audience){"Аудиторія 2", 200});
    addAudience(&list, (Audience){"Аудиторія 3", 130});
    
    printf("Вміст списку:\n");
    printList(&list);

    printf("\nАудиторії, що вміщують більше 150 осіб:\n");
    findLargeAudiences(&list, 150);

    printf("\nДодавання нової аудиторії:\n");
    addAudience(&list, (Audience){"Аудиторія 4", 250});
    printList(&list);

    printf("\nВидалення аудиторії за індексом 1:\n");
    removeAudience(&list, 1);
    printList(&list);

    printf("\nСортування аудиторій за кількістю місць:\n");
    sortList(&list, compareByCapacity);
    printList(&list);

    // Звільнення пам'яті
    free(list.array);

    printf("\nТест завершено успішно\n");
}

int main() {
    runMainTest();
    return 0;
}
