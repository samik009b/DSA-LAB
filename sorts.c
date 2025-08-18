#include <stdio.h>
#define SIZE 7
int a[SIZE] = {1, 3, 2, 5, 8, 10, 9};

void xorSwap(int *x, int *y) {
    if (x == y) return;  
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int partition(int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            xorSwap(&a[i], &a[j]);
        }
    }
    xorSwap(&a[i+1], &a[high]);  
    return i + 1;
}
                
void quickSort(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quicksort(low, pivotIndex - 1);
        quicksort(pivotIndex + 1, high);
    }
}

int main() {
    quicksort(0, SIZE - 1);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    return 0;
}
