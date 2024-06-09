#ifndef LIB_H
#define LIB_H

/**
 * @brief Створює суцільний рівнобедрений трикутник із заданих символів.
 *
 * @param height Висота трикутника.
 * @param base_width Ширина трикутника.
 * @param fill_char Символ для заповнення трикутника.
 * @param output_file Шлях до файлу для запису результату.
 */
void create_triangle(int height, int base_width, char fill_char, const char *output_file);

#endif // LIB_H
