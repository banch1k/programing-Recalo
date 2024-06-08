#include <stdio.h>
#include "lib.h"

// Функція для виведення масиву на екран
void print_array(const int *array, int length)
{
	printf("[");
	for (int i = 0; i < length; i++) {
		printf("%d", array[i]);
		if (i < length - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main()
{
	// Визначення і ініціалізація масиву
	int array[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
	int length = sizeof(array) / sizeof(array[0]); // Обчислення довжини масиву

	// Зберігання мінімального та максимального значень
	int min, max;
	find_min_max(array, length, &min, &max); // Знаходження мінімального та максимального значень
	printf("Min: %d, Max: %d\n", min, max); // Виведення мінімального та максимального значень

	// Обчислення суми елементів між мінімальним та максимальним значеннями
	int sum = sum_between_min_max(array, length, min, max);
	printf("Сумма між min та max: %d\n", sum); // Виведення суми

	// Масив для збереження елементів між мінімальним та максимальним значеннями
	int result[100];
	int result_length;
	// Заповнення нового масиву елементами між мінімальним та максимальним значеннями
	extract_between_min_max(array, length, min, max, result, &result_length);
	printf("Елементи між min та max: ");
	print_array(result, result_length); // Виведення нового масиву

	return 0;
}
