#ifndef LIB_H
#define LIB_H

#include <stddef.h> // Для size_t

// Прототипи функцій
void readFile(const char *filename, char *buffer, size_t size);
void countVowelsAndConsonants(const char *text, int *vowels, int *consonants);
void printResult(int vowels, int consonants);

#endif /* LIB_H */
