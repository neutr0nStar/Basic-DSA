#include <iostream>
using namespace std;

// Time complexity: O(logn)

// Binary search
// @param a: array to search in
// @param beg: lower index of array
// @param end: upper index of array
// @param k: key to search for
int binary_search(int a[], int beg, int end, int k) {
    int mid;
    if(end >= beg) {
        mid = beg + (end - beg) / 2;
        if(a[mid] == k) {
            return mid;
        } else if(a[mid] < k) {
            return binary_search(a, beg, mid-1, k);
        }else{
            return binary_search(a, mid+1, end, k);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    cout << binary_search(arr, 0, 4, 5) << endl;
    return 0;
}