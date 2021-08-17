#include <iostream>
using namespace std;

/**
 * Merge sort uses recursion
 * the basic idea is to split array into two parts, sort them, 
 * then merge the two sorted array into one sorted array
 * To sort the array, we split them again, until we reach an array with one element
 * an array with one element is always sorted
 * then make our way back up
 */

// Time complexity: O(nlogn)
// Not in place sorting algorithm, takes extra memory

// Merge two sorted array into on sorted array
// @param a : array to put sorted elemets in
// @param beg : beginning of array 1
// @param mid : end of array 1 (mid+1 is beginnig of array 2)
// @param beg : end of array 2
void merge(int a[], int beg, int mid, int end) {
    // size of the two arrays
    int nl = mid - beg + 1;
    int nr = end - mid;

    // the two arrays to be merged
    int l[nl], r[nr]; // declare
    for(int i = 0; i < nl; i++) l[i] = a[beg+i];   // initialize l with elements
    for(int i = 0; i < nr; i++) r[i] = a[mid+1+i]; // initialize r with elements

    int i, j; // indices for iterating through l and r arrays
    i = j = 0;

    int k = beg; // index for iterating through 'a' array

    // start mergin the two sorted arrays
    while(i < nl && j < nr) {
        if(l[i] < r[j])
            a[k++] = l[i++];
        else
            a[k++] = r[j++];
    }
    // It may happen that one array is exhausted, while other still has some elements
    while(i < nl) a[k++] = l[i++];
    while(j < nr) a[k++] = r[j++];
}

// @param a: array
// @param beg: beginning index of array
// @param end: end index of array
void merge_sort(int a[], int beg, int end) {
    if(end <= beg) return; // base case for recursion
    int mid = beg + (end - beg) / 2; // find mid for given array
    merge_sort(a, beg  , mid);   // sort the left half [beg...mid]
    merge_sort(a, mid+1, end); // sort the right half [med+1...end]
    merge(a, beg, mid, end); // merge the two sorted arrays (left and right)
}

int main() {
    int arr[] = {3, 2, 5, 11, 6};
    // beginnig index is zero
    // end index is size-1 (because arrays are 0 based)
    merge_sort(arr, 0, (sizeof(arr)/sizeof(arr[0])) - 1);
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}