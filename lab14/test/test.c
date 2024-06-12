#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Тестові дані
const char* test_filename = "test_input.txt";

// Функція для створення тестового файлу
void create_test_file() {
    FILE* file = fopen(test_filename, "w");
    if (!file) {
        perror("Не вдається створити тестовий файл");
        exit(1);
    }

    fprintf(file, "3\n");
    fprintf(file, "1 A1 50 1 1 needs_repair так 2 так 10\n");
    fprintf(file, "0 B2 100 2 2 does_not_need_repair ні 1 ні 0\n");
    fprintf(file, "1 C3 200 3 3 needs_cosmetic_repair так 3 ні 5\n");

    fclose(file);
}

void test_read_audiences() {
    Audience* audiences;
    int count;

    read_audiences(test_filename, &audiences, &count);

    assert(count == 3);
    assert(audiences[0].occupied == 1);
    assert(strcmp(audiences[0].name, "A1") == 0);
    assert(audiences[0].capacity == 50);
    assert(audiences[0].location.building == 1);
    assert(audiences[0].location.floor == 1);
    assert(strcmp(audiences[0].condition, "needs_repair") == 0);
    assert(strcmp(audiences[0].has_projector, "так") == 0);
    assert(audiences[0].board_count == 2);
    assert(audiences[0].computer_count == 10);
    assert(strcmp(audiences[0].has_lab_assistant, "так") == 0);

    assert(audiences[1].occupied == 0);
    assert(strcmp(audiences[1].name, "B2") == 0);
    assert(audiences[1].capacity == 100);
    assert(audiences[1].location.building == 2);
    assert(audiences[1].location.floor == 2);
    assert(strcmp(audiences[1].condition, "does_not_need_repair") == 0);
    assert(strcmp(audiences[1].has_projector, "ні") == 0);
    assert(audiences[1].board_count == 1);
    assert(audiences[1].computer_count == 0);
    assert(strcmp(audiences[1].has_lab_assistant, "ні") == 0);

    assert(audiences[2].occupied == 1);
    assert(strcmp(audiences[2].name, "C3") == 0);
    assert(audiences[2].capacity == 200);
    assert(audiences[2].location.building == 3);
    assert(audiences[2].location.floor == 3);
    assert(strcmp(audiences[2].condition, "needs_cosmetic_repair") == 0);
    assert(strcmp(audiences[2].has_projector, "так") == 0);
    assert(audiences[2].board_count == 3);
    assert(audiences[2].computer_count == 5);
    assert(strcmp(audiences[2].has_lab_assistant, "ні") == 0);

    free(audiences);
}

void test_write_audiences() {
    Audience* audiences;
    int count;

    read_audiences(test_filename, &audiences, &count);
    const char* output_filename = "test_output.txt";
    write_audiences(output_filename, audiences, count);

    Audience* audiences_out;
    int count_out;

    read_audiences(output_filename, &audiences_out, &count_out);

    assert(count == count_out);
    for (int i = 0; i < count; ++i) {
        assert(audiences[i].occupied == audiences_out[i].occupied);
        assert(strcmp(audiences[i].name, audiences_out[i].name) == 0);
        assert(audiences[i].capacity == audiences_out[i].capacity);
        assert(audiences[i].location.building == audiences_out[i].location.building);
        assert(audiences[i].location.floor == audiences_out[i].location.floor);
        assert(strcmp(audiences[i].condition, audiences_out[i].condition) == 0);
        assert(strcmp(audiences[i].has_projector, audiences_out[i].has_projector) == 0);
        assert(audiences[i].board_count == audiences_out[i].board_count);
        assert(audiences[i].computer_count == audiences_out[i].computer_count);
        assert(strcmp(audiences[i].has_lab_assistant, audiences_out[i].has_lab_assistant) == 0);
    }

    free(audiences);
    free(audiences_out);
}

void test_find_large_audiences() {
    Audience* audiences;
    int count;

    read_audiences(test_filename, &audiences, &count);

    int large_count;
    Audience* large_audiences = find_large_audiences(audiences, count, &large_count);

    assert(large_count == 1);
    assert(strcmp(large_audiences[0].name, "C3") == 0);

    free(audiences);
    free(large_audiences);
}

int main() {
    create_test_file();
    test_read_audiences();
    test_write_audiences();
    test_find_large_audiences();

    printf("Усі тести пройдені успішно.\n");

    return 0;
}
