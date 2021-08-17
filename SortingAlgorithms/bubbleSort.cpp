#include <iostream>
using namespace std;

/**
 * In bubble sort, we compare 2 consecutive elements
 * and swap if next element is greater than current (for ascending)
 * and do this n-1 times, this will take the biggest element to the end.
 * Now we will repeat this again and again, till we move all big elements to right
 */

// Time complexity O(n^2)

void bubble_sort(int a[], int s) {
    // as we are taking array as pointer, we don't have to return anything
    // modifying array in this function will modify original array
    int temp; // used for swapping
    bool swapped; // flag to check if some element was swapped
    for(int i = 0; i < s-1; i++) { // n-1 times
        swapped = false;
        for(int j = 0; j < s-1-i; j++) {
            if(a[j] > a[j+1]){
                swapped = true;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(!swapped) break; // if no swap has occured, array is sorted now, no need to go further
    }
}

int main() {
    int arr[] = {3, 2, 5, 11, 6};
    bubble_sort(arr, 5);
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}