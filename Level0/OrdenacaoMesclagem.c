#include <stdio.h>

// Função para mesclar duas sublistas ordenadas
void merge(int arr[], int left, int middle, int right) {
    // Quantidade de elementos dos vetores subdivididos
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    // Crie sub arrays temporários
    int temp_left[n1];
    int temp_right[n2];
    
    // Copie os elementos para os subarranjos temporários
    for (int i = 0; i < n1; i++) {
        temp_left[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        temp_right[j] = arr[middle + 1 + j];
    }
    
    // Mesclar os subarranjos temporários de volta no arr[]
    int i = 0;
    int j = 0;
    int k = left;
    
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
    
    // Copiar os elementos restantes de temp_left[], se houver algum
    while (i < n1) {
        arr[k] = temp_left[i];
        i++;
        k++;
    }
    
    // Copiar os elementos restantes de temp_right[], se houver algum
    while (j < n2) {
        arr[k] = temp_right[j];
        j++;
        k++;
    }
}

// Função para ordenação por mesclagem
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2; // index da metada do array
        
        // identificando e fornecendo a primeira e a segunda metade do array
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        
        // Mescla as duas metades ordenadas
        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]); //tamanho do arr em bytes divido pelo tamanho de um unico elemento em bytes.
    
    printf("Array original:\t");
    printf("[");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
        }
    printf("]");
    mergeSort(arr, 0, arr_size - 1);
    
    printf("\nArray ordenado:\t");
    printf("[");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    return 0;
}

