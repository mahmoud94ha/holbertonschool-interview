#include <stdio.h>

int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL) {
        return -1;
    }
    int left = 0;
    int right = size - 1;
    int mid;
    int index = -1;

    while (left <= right) {
        printf("Searching in array: ");
        for (int i = left; i <= right; i++) {
            printf("%d ", array[i]);
            if (i < right) {
                printf(", ");
            }
        }
        printf("\n");

        mid = left + (right - left) / 2;

        if (array[mid] == value) {
            index = mid;
            right = mid - 1;  // to search for the first occurrence of the value
        } else if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return index;
}
