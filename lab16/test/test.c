#include "list.h"
#include <assert.h>
#include <stdio.h>

// Функція для тестування додавання та видалення аудиторій
void testAddRemoveAudience() {
    AudienceList list;
    initList(&list);

    addAudience(&list, (Audience){"Test1", 100});
    addAudience(&list, (Audience){"Test2", 200});
    assert(list.head != NULL);
    assert(list.head->next != NULL);

    removeAudience(&list, 1);
    assert(list.head != NULL);
    assert(list.head->next == NULL);

    removeAudience(&list, 0);
    assert(list.head == NULL);
}

int main() {
    testAddRemoveAudience();
    printf("Усі тести пройдено.\n");
    return 0;
}
