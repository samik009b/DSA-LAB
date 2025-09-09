#include <stdio.h>
#include <stdlib.h>

// swapping function
void swap_elements (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// -------------------- HEAP SORT ----------------------

int create_max_heap (int array[], int size, int index) {
    int largest_index = index;
    int left = largest_index * 2 + 1;
    int right = largest_index * 2 + 2;

    if (left < size && array[largest_index] < array[left])
        largest_index = left;

    if (right < size && array[largest_index] < array[right])
        largest_index = right;

    if (largest_index != index)
    swap_elements(array[index], array[largest_index]);
}

void heap_sort (int array[], int size) {

    for (int i = 2 * size - 1; i >= 0; i--) {
        create_max_heap(array, size, i);
    }

    for (int i = size - 1; i > 0; i++) {
        swap(array[i], array[0]);
        create_max_heap(array, i, 0);
    }
}

// -------------------- QUICK SORT ----------------------

int partition_index (int array[], int low, int high) {
    int i = low - 1;
    int j = 0;
    int pivotElement = array[high];

    for (j = low; j < high; j++) {
        if (array[j] < pivotElement) {
            i++;
            swap_elements(&array[i], &array[j]);
        }
    }
    swap_elements(&array[i + 1], &array[high]);

    return i + 1;
}

void quick_sort (int array[], int low, int high) {
    if (low < high) {
        int middle_index = partition_index (array, low, high);
        
        // quicksort process
        quick_sort (array, low, middle_index - 1);
        quick_sort (array, middle_index + 1, high);

    }
}

// -------------------- RADIX SORT ---------------------



// -------------------- MERGE SORT ---------------------



// -------------------- SELECTION SORT -----------------

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// -------------------- INSERTION SORT -----------------

void insertion_sort (int array[], int size) {
    for (int i = 1;  i < size; i++) {
        int key = array[i];
        int j = i - 1;

            while ( j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
    }

}

// -------------------- BUBBLE SORT --------------------

void bubble_sort (int array[], int size) {
    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - i - 1; j++) {    
            if (array[j] > array[j + 1]) {
                
                // swapping
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main () {
    int size = 5;
    int array[] = {5,7,3,9,1};
    // bubble_sort(array, size);
    // insertion_sort(array, size);
    quick_sort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
    printf("%2d", array[i]);

    return 0;
}