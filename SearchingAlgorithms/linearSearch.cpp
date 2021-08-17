#include <iostream>
using namespace std;

// Time complexity: O(n)

// Linear search
// @param a: array to search in
// @param n: size of array
// @param k: key to search for
int linear_search(int a[], int n, int k) {
    for(int i = 0; i < n; i++) {
        if(a[i] == k) return i;
    }
    return -1;
}

int main() {
    int arr[] = {1, 5, 3, 7, 4, 33};
    cout << linear_search(arr, 6, 4) << endl;
    return 0;
}