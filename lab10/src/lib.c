#include "lib.h"
#include <limits.h>

// Функція для знаходження мінімального та максимального елементів в масиві
void find_min_max(const int *array, int length, int *min, int *max)
{
	*min = INT_MAX; // Ініціалізація мінімального значення максимальним можливим числом
	*max = INT_MIN; // Ініціалізація максимального значення мінімальним можливим числом

	// Проходження через весь масив для знаходження мінімального та максимального значень
	for (int i = 0; i < length; i++) {
		if (array[i] < *min) {
			*min = array[i]; // Оновлення мінімального значення
		}
		if (array[i] > *max) {
			*max = array[i]; // Оновлення максимального значення
		}
	}
}

// Функція для обчислення суми елементів між мінімальним та максимальним значеннями в масиві
int sum_between_min_max(const int *array, int length, int min, int max)
{
	int sum = 0; // Змінна для зберігання суми
	int min_index = -1, max_index = -1; // Індекси мінімального та максимального значень

	// Знаходження індексів мінімального та максимального значень
	for (int i = 0; i < length; i++) {
		if (array[i] == min && min_index == -1) {
			min_index = i; // Збереження індексу мінімального значення
		}
		if (array[i] == max) {
			max_index = i; // Збереження індексу максимального значення
		}
	}

	// Перемикання індексів, якщо індекс мінімального значення більший за індекс максимального значення
	if (min_index > max_index) {
		int temp = min_index;
		min_index = max_index;
		max_index = temp;
	}

	// Обчислення суми елементів між мінімальним та максимальним значеннями
	for (int i = min_index + 1; i < max_index; i++) {
		sum += array[i];
	}

	return sum; // Повернення суми
}

// Функція для створення нового масиву з елементів між мінімальним та максимальним значеннями
void extract_between_min_max(const int *array, int length, int min, int max, int *result, int *result_length)
{
	int min_index = -1, max_index = -1; // Індекси мінімального та максимального значень

	// Знаходження індексів мінімального та максимального значень
	for (int i = 0; i < length; i++) {
		if (array[i] == min && min_index == -1) {
			min_index = i; // Збереження індексу мінімального значення
		}
		if (array[i] == max) {
			max_index = i; // Збереження індексу максимального значення
		}
	}

	// Перемикання індексів, якщо індекс мінімального значення більший за індекс максимального значення
	if (min_index > max_index) {
		int temp = min_index;
		min_index = max_index;
		max_index = temp;
	}

	*result_length = 0; // Ініціалізація довжини результатного масиву

	// Заповнення результатного масиву елементами між мінімальним та максимальним значеннями
	for (int i = min_index + 1; i < max_index; i++) {
		result[(*result_length)++] = array[i];
	}
}
