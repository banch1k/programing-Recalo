#include <stdio.h>
#include "lib.h"

void run_tests();

int main() {
    run_tests();
    return 0;
}

void run_tests() {
    int a = 10, b = 2, очікуємо = 20;
    int result = multiply(a, b);
    printf("1-ий тест: %d * %d = %d (очікуємо %d) -> %s\n", a, b, result, очікуємо, result == очікуємо ? "пройдено" : "не пройдено");

    a = 3; b = 17; очікуємо = 51;
    result = multiply(a, b);
    printf("2-ий тест: %d * %d = %d (очікуємо %d) -> %s\n", a, b, result, очікуємо, result == очікуємо ? "пройдено" : "не пройдено");

    a = 0; b = 111; очікуємо = 0;
    result = multiply(a, b);
    printf("Test 3: %d * %d = %d (очікуємо %d) -> %s\n", a, b, result, очікуємо, result == очікуємо ? "пройдено" : "не пройдено");
}
