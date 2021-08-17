#include <iostream>
using namespace std;

/**
 * Quick sort is similar to merge sort, but quick sort sorts inplace
 * first, we tak a pivot element, and move elements less than it to left of it in array
 * and greater elements to right of it in array.
 * then we do quick sort on left and right side of the array 
 * hence sorting recursively
 */

// Time complexity:
//     O(nlogn) - average case
//     O(n^2) - worst case

// Partition the array
// @param a[]: array to be partitioned
// @param start: start index of array
// @param end: end index of array
int partition(int a[], int start, int end) {
    int pivot = a[end]; // take end element as pivot
    int partition_idx = start; // set partition index as start initially
    int temp; // temporary variable used for sorting
    for(int i = start; i < end; i++) { // loop through array
        if(a[i] <= pivot) { // if current element is less than pivot
            // swap a[i] and pivot
            temp = a[i];
            a[i] = a[partition_idx];
            a[partition_idx] = temp;
            partition_idx++; // increment partition index
        }
    }
    // lastly, swap pivot (end element) and element at partition index
    temp = a[partition_idx];
    a[partition_idx] = a[end];
    a[end] = temp;
    return partition_idx;
}

// Quick sort algorithm
// @param a[]: array to be sorted
// @param start: start index of array
// @param end: end index of array
void quick_sort(int a[], int start, int end) {
    if(start >= end) return;
    int partition_idx = partition(a, start, end);
    quick_sort(a, start, partition_idx-1);
    quick_sort(a, partition_idx+1, end);
}

int main() {
    int arr[] = {2, 1, 5, 3, 6, 4};
    quick_sort(arr, 0, 5);
    for(int i = 0; i < 6; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}