#ifndef LIB_H
#define LIB_H

typedef struct {
    int building; // Номер будівлі
    int floor; // Номер поверху
} Location; // Структура для зберігання місця розташування аудиторії

typedef struct {
    int occupied; // Чи зайнята аудиторія (так/ні)
    char name[10]; // Назва аудиторії
    int capacity; // Вмістимість аудиторії
    Location location; // Місце розташування аудиторії
    char condition[30]; // Стан аудиторії ('needs_repair', 'needs_cosmetic_repair', 'does_not_need_repair')
    char has_projector[3]; // Наявність проектору (так/ні)
    int board_count; // Кількість дошок
    int computer_count; // Кількість комп'ютерів
    char has_lab_assistant[3]; // Наявність лаборанта (так/ні)
} Audience;  // Структура для зберігання даних про аудиторії

// Прототипи функцій
void read_audiences(const char* filename, Audience** audiences, int* count);
void write_audiences(const char* filename, Audience* audiences, int count);
void print_audiences(Audience* audiences, int count);
Audience* find_large_audiences(Audience* audiences, int count, int* result_count);
void sort_audiences(Audience* audiences, int count, int (*compare)(const Audience*, const Audience*));

#endif // LIB_H
