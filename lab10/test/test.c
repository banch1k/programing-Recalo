#include <stdio.h>
#include "lib.h"

int main() {
    int array1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int length1 = sizeof(array1) / sizeof(array1[0]);
    int min1, max1;

    find_min_max(array1, length1, &min1, &max1);
    printf("Min1: %d, Max1: %d\n", min1, max1);

    int array2[] = {1, 2, 3, 4, 5};
    int length2 = sizeof(array2) / sizeof(array2[0]);
    int min2, max2;

    find_min_max(array2, length2, &min2, &max2);
    printf("Min2: %d, Max2: %d\n", min2, max2);

    int array3[] = {-5, -3, -1, 0, 1, 3, 5};
    int length3 = sizeof(array3) / sizeof(array3[0]);
    int min3, max3;

    find_min_max(array3, length3, &min3, &max3);
    printf("Min3: %d, Max3: %d\n", min3, max3);

    return 0;
}
