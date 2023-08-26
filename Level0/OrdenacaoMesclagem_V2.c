#include <stdio.h>

// Função para mesclar duas sublistas ordenadas
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int temp_left[n1];
    int temp_right[n2];

    for (int i = 0; i < n1; i++) {
        temp_left[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        temp_right[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (temp_left[i] <= temp_right[j]) {
            arr[k] = temp_left[i];
            i++;
        } else {
            arr[k] = temp_right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = temp_left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = temp_right[j];
        j++;
        k++;
    }
}

// Função de ordenação por mesclagem
void mergeSort(int arr[], int arr_size) {
    int subarray_size = 1;

    while (subarray_size < arr_size) {
        int left = 0;

        while (left < arr_size - 1) {
            int middle = left + subarray_size - 1;
            int right = middle + subarray_size;

            if (right >= arr_size) {
                right = arr_size - 1;
            }

            merge(arr, left, middle, right);
            left = right + 1;
        }

        subarray_size *= 2;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, arr_size);

    printf("\nArray ordenado:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
