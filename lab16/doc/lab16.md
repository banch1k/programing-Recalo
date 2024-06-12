# Лабораторна робота №16. (x2) Динамічні списки

## 1 Вимоги

### 1.1 Розробник

* Рекало Іван Сергійович;
* студент групи КН923г;
* 12-чер-2024.

### 1.2 Завдання

Розробити функціонал для роботи з односпрямованим списком:

- читання даних з файлу;
- запис даних у файл;
- вивід вмісту списку на екран;
- пошук аудиторій, що вміщують більше 150 осіб;
- додавання об’єкта у кінець списку;
- видалення об’єкта зі списку за індексом;
- сортування вмісту списку за вмістимістю.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для управління інформацією про аудиторії за допомогою односпрямованого списку. Користувач може додавати нові аудиторії, видаляти існуючі, сортувати список за вмістимістю, зберігати та зчитувати дані з файлів, а також знаходити великі аудиторії.

### 2.2 Опис логічної структури

#### Функція додавання аудиторії
```C
void addAudience(AudienceList *list, Audience audience);
```

*Призначення*: додає нову аудиторію в кінець списку.

*Опис роботи*: функція створює новий вузол списку, копіює дані аудиторії до вузла, додає вузол у кінець списку.

*Аргументи*:

- list - вказівник на список аудиторій.
- audience - структура з даними про аудиторію.

#### Функція видалення аудиторії за індексом
```C
void removeAudience(AudienceList *list, int index);
```

*Призначення*: видаляє аудиторію зі списку за заданим індексом.

*Опис роботи*: функція знаходить вузол за індексом і видаляє його зі списку, вивільняючи пам'ять.

*Аргументи*:

- index - індекс вузла, який потрібно видалити.

#### Головна функція
```C
int main();
```

*Призначення*: основна функція, яка викликається при запуску програми.

*Опис роботи*: ініціалізує список аудиторій, додає тестові дані, обробляє меню користувача для взаємодії зі списком.

#### Структура проекту
```
                 └── lab16/
                     ├── Makefile
                     ├── Doxyfile
                     ├── README.md
                     ├── doc
                         └── lab16.md
                     ├── src
                         ├── list.c
                         ├── list.h
                         ├── main.c
                         ├── entity.c
                         ├── entity.h
                         ├── menu.c
                         ├── menu.h
                     └── test
                         └── test.c
```

### 2.3 Важливі фрагменти програми

#### Ініціалізація списку
```C
void initList(AudienceList *list) {
    list->head = NULL;
}
```

#### Додавання аудиторій
```C
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
```

#### Видалення аудиторії за індексом
```C
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
```

#### Сортування списку за вмістимістю
```C
void sortList(AudienceList *list, int (*compare)(const void *, const void *)) {
    if (!list->head) return;

    size_t size = 0;
    AudienceNode *temp = list->head;
    while (temp) {
        size++;
        temp = temp->next;
    }

    Audience *array = malloc(size * sizeof(Audience));
    temp = list->head;
    for (size_t i = 0; i < size; i++) {
        array[i] = temp->data;
        temp = temp->next;
    }

    qsort(array, size, sizeof(Audience), compare);

    temp = list->head;
    for (size_t i = 0; i < size; i++) {
        temp->data = array[i];
        temp = temp->next;
    }

    free(array);
}
```

#### Зчитування даних з файлу
```C
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
```

#### Запис даних у файл
```C
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
```

#### Перевірка відсутності витоків пам'яті за допомогою утиліти valgrind
```C
==52204== Memcheck, a memory error detector
==52204== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==52204== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==52204== Command: ./main
==52204== 
Меню:
1. Вивід списку
2. Додати аудиторію
3. Знайти великі аудиторії
4. Видалити аудиторію
5. Сортувати список
6. Зчитати дані з файлу
7. Записати дані у файл
8. Вихід
Виберіть опцію: 8
==52204== 
==52204== HEAP SUMMARY:
==52204==     in use at exit: 192 bytes in 3 blocks
==52204==   total heap usage: 5 allocs, 2 frees, 2,240 bytes allocated
==52204== 
==52204== 192 (64 direct, 128 indirect) bytes in 1 blocks are definitely lost in loss record 3 of 3
==52204==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==52204==    by 0x1094B0: addAudience (in /home/banch1k/Стільниця/programing-Recalo/lab16/src/main)
==52204==    by 0x109377: main (in /home/banch1k/Стільниця/programing-Recalo/lab16/src/main)
==52204== 
==52204== LEAK SUMMARY:
==52204==    definitely lost: 64 bytes in 1 blocks
==52204==    indirectly lost: 128 bytes in 2 blocks
==52204==      possibly lost: 0 bytes in 0 blocks
==52204==    still reachable: 0 bytes in 0 blocks
==52204==         suppressed: 0 bytes in 0 blocks
==52204== 
==52204== For lists of detected and suppressed errors, rerun with: -s
==52204== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

#### Модульний тест
```C
./dist/test.bin
Усі тести пройдено.
```

## 3 Варіанти використання

#### Програма може бути використана для:

1. Управління списком аудиторій.
2. Зберігання та обробки даних про аудиторії (додавання, видалення, сортування, пошук аудиторій, запис даних про аудиторії)

## Висновки

Лабораторна робота навчила нас працювати з односпрямованим списком (додавати, видаляти, сортувати список, шукати аудиторії, зберігати дані про аудиторії та зберігати та зчитувати дані з файлів.