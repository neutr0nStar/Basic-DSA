#include <iostream>
using namespace std;

/**
 * Selection sort is an inplace sorting algorithm
 * left side of array will be sorted, right will be unsorted
 * left will grow, right will shrink
 * we find the min element, and swap it with element at 0th index
 * then we find min element in remaining array (except 0th element),
 * and swap it with element at 1st index, and so on
 */

// Time complexity: O(n^2)

void selection_sort(int a[], size_t s) {
    // as we are taking array as pointer, we don't have to return anything
    // modifying array in this function will modify original array
    int min_idx;
    int temp;
    for(int i = 0; i < s-1; i++) { 
        // we only need to sort till second last element, last will be automatically sorted
        min_idx = i; // finding index of min element
        for(int j = i+1; j < s; j++) {
            if(a[j] < a[min_idx])
                min_idx = j;
        }
        // swap with element with index i
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

int main() {
    int arr[] = {11, 33, 22, 45, 66};
    selection_sort(arr, 5);
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}