# Лабораторна робота №13. Взаємодія з файлами

## 1 Вимоги

### 1.1 Розробник

* Рекало Іван Сергійович;
* студент групи КН923г;
* 09-чер-2024.

### 1.2 Завдання

Створити програму, яка генерує рівнобедрений трикутник із заданих символів і записує його в текстовий файл. Параметри трикутника зчитуються з вхідного файлу.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для створення рівнобедреного трикутника із заданих символів та запису його у текстовий файл. Параметри трикутника зчитуються з вхідного файлу і записуються у вихідний файл.

### 2.2 Опис логічної структури

#### Функція для створення трикутника
```C
void create_triangle(int height, int base_width, char fill_char, const char *output_file)
```

*Призначення*: створює рівнобедрений трикутник із заданих символів і записує його в текстовий файл.

*Опис роботи*: функція відкриває файл для запису, генерує трикутник заданих параметрів і записує його у файл.

**Аргументи**:

- height - висота трикутника;
- base_width - ширина трикутника;
- fill_char - символ для заповнення трикутника;
- output_file - шлях до файлу для запису результату.

#### Головна функція
```C
int main(int argc, char *argv[])
```

*Призначення*: основна функція, яка викликається при запуску програми.

*Опис роботи*: зчитує параметри трикутника з вхідного файлу, викликає функцію create_triangle для генерації трикутника і запису його у вихідний файл.

**Аргументи**:

- argc - кількість аргументів командного рядка;
- argv - масив аргументів командного рядка.

#### Структура проекту
```
                 └── lab13/
                     ├── Makefile
                     ├── Doxyfile
                     ├── README.md
                     ├── assets
                         └── input.txt
                     ├── doc
                         └── lab13.md
                     ├── src
                         ├── lib.c
                         ├── lib.h
                         ├── main.c
                     └── test
                         └── test.c
```

### 2.3 Важливі фрагменти програми

#### Створення трикутника
```C
void create_triangle(int height, int base_width, char fill_char, const char *output_file) {
    FILE *file = fopen(output_file, "w");
    if (!file) {
        perror("Неможливо відкрити вихідний файл");
        exit(EXIT_FAILURE);
    }

    int midpoint = base_width / 2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < base_width; j++) {
            if (j >= (midpoint - i) && j <= (midpoint + i)) {
                fprintf(file, "%c ", fill_char);
            } else {
                fprintf(file, "  ");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
```

#### Головна функція
```C
int main(int argc, char *argv[]) {
    // Перевірка кількості аргументів
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    // Відкриття вхідного файлу для читання
    FILE *file = fopen(input_file, "r");
    if (!file) {
        perror("Неможливо відкрити вхідний файл");
        return EXIT_FAILURE;
    }

    int height, base_width;
    char fill_char;

    // Читання параметрів трикутника з файлу
    if (fscanf(file, "%d %d %c", &height, &base_width, &fill_char) != 3) {
        fprintf(stderr, "Невірний формат вхідного файлу\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Закриття вхідного файлу
    fclose(file);

    // Функція для створення трикутника
    create_triangle(height, base_width, fill_char, output_file);

    return EXIT_SUCCESS;
}
```

#### Перевірка відсутності витоків пам'яті за допомогою утиліти valgrind
```C
==52044== Memcheck, a memory error detector
==52044== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==52044== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==52044== Command: ./main
==52044== 
Usage: ./main <input_file> <output_file>
==52044== 
==52044== HEAP SUMMARY:
==52044==     in use at exit: 0 bytes in 0 blocks
==52044==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==52044== 
==52044== All heap blocks were freed -- no leaks are possible
==52044== 
==52044== For lists of detected and suppressed errors, rerun with: -s
==52044== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

#### Модульний тест
```C
./dist/test.bin
Тест пройдено
```

## 3 Варіанти використання

#### Програма може бути використана для:

1. Генерації рівнобедреного трикутника із заданих символів.
2. Роботи з файлами для зчитування параметрів та запису результатів у текстовий файл.

## Висновки

Лабораторна робота навчила нас створювати рівнобедрені трикутники із заданих символів, зчитувати дані з файлів та записувати результати у текстові файли.