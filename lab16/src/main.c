#include "list.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    AudienceList list;
    initList(&list);

    addAudience(&list, (Audience){"Аудиторія 1", 50});
    addAudience(&list, (Audience){"Аудиторія 2", 200});
    addAudience(&list, (Audience){"Аудиторія 3", 130});

    handleMenu(&list);

    return 0;
}
