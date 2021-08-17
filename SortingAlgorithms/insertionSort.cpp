#include <iostream>
using namespace std;

/**
 * Insertion sort divides array in two part, sorted and unsorted
 * sorted on left, grows fron one element to all element
 * unsorted on right, shrinks from n-1 elements to 0 elements
 * we take the leftmost element from unsorted(right) part of the array
 * this creates a hole in array (not really, but for sake of understanding)
 * then, we move left from that position until we reach a position where by putting
 * the current element, yield a sorted array
 */

// Time complexity O(n^2)
// In practical cases, insertion sort is considered better than bubble and selection sort

void insertion_sort(int a[], int n) {
    // value to store value of element to be shifted
    // hole, to keep track of the position in sorted part 
    // at which current element is to be inserted
    int value, hole; 
    for(int i = 1; i < n; i++) { // n-1 times
        value = a[i];
        hole = i;
        while(hole > 0 && a[hole-1] > value){ // shifting hole
            a[hole] = a[hole-1];
            hole--;
        }
        a[hole] = value;
    }
}

int main() {
    int arr[] = {3, 2, 5, 11, 6};
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}