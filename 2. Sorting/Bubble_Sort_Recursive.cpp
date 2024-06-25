/*
Time Complexity : 
Best Case    : O(n²)
Average Case : O(n²)
Worst Case   : O(n²)
*/

/* Space Complexity : O(n) 
The space complexity is O(n) due to the recursive function calls. Each recursive call
adds a new frame to the call stack, and the maximum depth of recursion will be n.
*/

#include <iostream>
using namespace std;

// A function to implement bubble sort recursively
void bubbleSortRecursive(int arr[], int n) {
    // Base case: If the array size is 1, it's already sorted
    if (n == 1) {
        return;
    }

    // One pass of bubble sort. After this pass, the largest element is moved to the end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Swap arr[i] and arr[i + 1]
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Largest element is fixed, recur for the remaining array
    bubbleSortRecursive(arr, n - 1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRecursive(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
