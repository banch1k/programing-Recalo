#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "lib.h"

void readFile(const char *filename, char *buffer, size_t size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Не вдалося відкрити файл '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fread(buffer, sizeof(char), size - 1, file);
    buffer[size - 1] = '\0'; // Завершення рядка
    fclose(file);
}

void countVowelsAndConsonants(const char *text, int *vowelCount, int *consonantCount) {
    const char *vowels = "AEIOUYaeiouy";
    const char *consonants = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    
    *vowelCount = 0;
    *consonantCount = 0;

    while (*text) {
        if (strchr(vowels, *text) != NULL) {
            (*vowelCount)++;
        } else if (strchr(consonants, *text) != NULL) {
            (*consonantCount)++;
        }
        text++;
    }
}

void printResult(int vowels, int consonants) {
    int total = vowels + consonants;
    if (total == 0) {
        printf("Текст не містить голосних або приголосних букв.\n");
        return;
    }
    float vowelPercentage = ((float)vowels / total) * 100;
    float consonantPercentage = ((float)consonants / total) * 100;

    printf("Голосних: %d (%.2f%%)\n", vowels, vowelPercentage);
    printf("Приголосних: %d (%.2f%%)\n", consonants, consonantPercentage);
}
