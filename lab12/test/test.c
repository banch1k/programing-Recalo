#include <stdio.h>
#include "lib.h"

void test_readFile() {
    char buffer[10000];
    readFile("assets/input.txt", buffer, sizeof(buffer));
    printf("Тест readFile:\n");
    printf("%s\n", buffer);
}

void test_countVowelsAndConsonants() {
    char text[] = "eeefdgdhf";
    int vowels = 0, consonants = 0;
    countVowelsAndConsonants(text, &vowels, &consonants);
    printf("Тест countVowelsAndConsonants:\n");
    printf("Приголосних: %d, Голосних: %d\n", vowels, consonants);
}

void test_printResult() {
    int vowels = 29;
    int consonants = 78;
    printf("Тест printResult:\n");
    printResult(vowels, consonants);
}

int main() {
    test_readFile();
    printf("\n");

    test_countVowelsAndConsonants();
    printf("\n");

    test_printResult();
    printf("\n");

    printf("Тестування завершено.\n");
    return 0;
}
