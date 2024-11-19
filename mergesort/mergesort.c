#include "mergesort.h"
#include <stdlib.h>
#include <string.h>

void merge(int values[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArray = (int*)malloc(n1 * sizeof(int));
    int* rightArray = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        leftArray[i] = values[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = values[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            values[k] = leftArray[i];
            i++;
        } else {
            values[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        values[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        values[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void mergesort_recursive(int values[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort_recursive(values, left, mid);
        mergesort_recursive(values, mid + 1, right);

        merge(values, left, mid, right);
    }
}

void mergesort(int size, int values[]) {
    if (size > 1) {
        mergesort_recursive(values, 0, size - 1);
    }
}
