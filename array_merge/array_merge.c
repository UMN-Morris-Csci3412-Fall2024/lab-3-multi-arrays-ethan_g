#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
    if (num_arrays == 0) {
        int* result = (int*)malloc(sizeof(int));
        result[0] = 0;
        return result;
    }

    // Calculate the total number of elements
    int total_size = 0;
    for (int i = 0; i < num_arrays; i++) {
        total_size += sizes[i];
    }

    // Merge all arrays into a single array
    int* merged_array = (int*)malloc(total_size * sizeof(int));
    int index = 0;
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            merged_array[index++] = values[i][j];
        }
    }

    // Sort the merged array
    mergesort(total_size, merged_array);

    // Remove duplicates
    int unique_count = 1;
    for (int i = 1; i < total_size; i++) {
        if (merged_array[i] != merged_array[i - 1]) {
            unique_count++;
        }
    }

    int* result = (int*)malloc((unique_count + 1) * sizeof(int));
    result[0] = unique_count;
    index = 1;
    result[index++] = merged_array[0];
    for (int i = 1; i < total_size; i++) {
        if (merged_array[i] != merged_array[i - 1]) {
            result[index++] = merged_array[i];
        }
    }

    free(merged_array);  // Free the allocated memory for merged_array
    return result;
}
