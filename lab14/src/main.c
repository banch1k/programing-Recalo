#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Використання: %s <ім'я_вхідного_файлу>\n", argv[0]);
        return 1;
    }

    const char* input_filename = argv[1];
    Audience* audiences;
    int count;

    // Читання даних про аудиторії з вхідного файлу
    read_audiences(input_filename, &audiences, &count);

    printf("Усі аудиторії:\n");
    // Вивод даних про всі аудиторії
    print_audiences(audiences, count);

    int large_count;
    // Пошук аудиторії, що вміщує більше 150 осіб
    Audience* large_audiences = find_large_audiences(audiences, count, &large_count);

    printf("\nВеликі аудиторії (вмістимість > 150):\n");
    // Вивод даних про великі аудиторії
    print_audiences(large_audiences, large_count);

    // Звільнення виділеної пам'яті
    free(audiences);
    free(large_audiences);

    return 0;
}
