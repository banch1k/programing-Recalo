#include "stdio.h"
#include "lib.h"

void test_multiply();

int main()
{
	test_multiply();
	return 0;
}

void test_multiply()
{
	int a = 10;
	int b = 2;
	int очікуємо = 20;
	int result = multiply(a, b);

	if (result == очікуємо) {
		printf("Пройдено: %d * %d = %d\n", a, b, result);
	} else {
		printf("Не пройдено: %d * %d очікуємо %d, отримуємо %d\n", a, b, очікуємо, result);
	}

	a = 3;
	b = 17;
	очікуємо = 51;
	result = multiply(a, b);
	if (result == очікуємо) {
		printf("Пройдено: %d * %d = %d\n", a, b, result);
	} else {
		printf("Не пройдено: %d * %d очікуємо %d, отримуємо %d\n", a, b, очікуємо, result);
	}

	a = 0;
	b = 111;
	очікуємо = 0;
	result = multiply(a, b);
	if (result == очікуємо) {
		printf("Пройдено: %d * %d = %d\n", a, b, result);
	} else {
		printf("Не пройдено: %d * %d очікуємо %d, отримуємо %d\n", a, b, очікуємо, result);
	}
}
