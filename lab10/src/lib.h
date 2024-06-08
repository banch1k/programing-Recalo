#ifndef LIB_H
#define LIB_H

/**
 * @brief Знаходить мінімальний та максимальний елементи в масиві.
 * 
 * @param array Масив цілих чисел.
 * @param length Довжина масиву.
 * @param min Змінна для збереження мінімального значення.
 * @param max Змінна для збереження максимального значення.
 */
void find_min_max(const int *array, int length, int *min, int *max);

/**
 * @brief Сума елементів масиву між мінімальним та максимальним елементами.
 * 
 * @param array Масив цілих чисел.
 * @param length Довжина масиву.
 * @param min Мінімальний елемент масиву.
 * @param max Максимальний елемент масиву.
 * @return int Сума елементів між мінімальним та максимальним елементами.
 */
int sum_between_min_max(const int *array, int length, int min, int max);

/**
 * @brief Створює новий масив, що містить елементи між мінімальним та максимальним елементами.
 * 
 * @param array Масив цілих чисел.
 * @param length Довжина масиву.
 * @param min Мінімальний елемент масиву.
 * @param max Максимальний елемент масиву.
 * @param result Масив для збереження результатів.
 * @param result_length Зінна для збереження довжини нового масиву.
 */
void extract_between_min_max(const int *array, int length, int min, int max, int *result, int *result_length);

#endif // LIB_H
