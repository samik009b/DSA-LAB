#include <iostream>
#include <vector>
using std::vector;
using std::cout; 
using std::cin;


void swap_elements (int *first_element, int *second_element) {
    int temp;
    temp = *first_element;
    *first_element = *second_element;
    *second_element = temp;
}

void heapify (int arr[], int size_of_arr, int i) {
    int largest_element_index = i;
    int left_node_index = 2*i + 1;
    int right_node_index= 2 * i + 2;

    // swapping the elements to build the max - heap
    if ( left_node_index< size_of_arr && arr[left_node_index] > arr[largest_element_index])
        largest_element_index = left_node_index;
    if ( right_node_index < size_of_arr && arr[right_node_index] > arr[largest_element_index])
       largest_element_index = right_node_index;

    if(largest_element_index != i) { 
        swap_elements(&arr[largest_element_index], &arr [i]);
        heapify( arr,  size_of_arr, largest_element_index);
    }
}

    void heap_sort (int arr[], int size_of_arr) {
        
        //building max - heap
        for(int i = size_of_arr / 2 - 1; i >= 0; i--)
        heapify(arr, size_of_arr, i);

        // extracting elements from heap and swapping them parent with root
        for (int i = size_of_arr - 1; i > 0; i--) {
            swap_elements(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
        
    }
int main () {
    vector<int> arr = {10, 5, 2, 8, 6, 0, 1, 3};
    auto size_of_arr = arr.size();

    heap_sort(arr.data(), size_of_arr);
    for (int i = 0; i < size_of_arr; i++)
        cout << arr[i] << " ";
    return 0;
}
