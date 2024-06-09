#include <stdio.h>
#include "lib.h"

int main() {
    char text[10000];
    int vowels = 0, consonants = 0;

    // Зчитує текст з файлу
    readFile("assets/input.txt", text, sizeof(text));

    // Кількість голосних і приголосних букв
    countVowelsAndConsonants(text, &vowels, &consonants);

    // Результат
    printResult(vowels, consonants);

    return 0;
}
