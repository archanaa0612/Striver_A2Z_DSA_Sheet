/*
Time Complexity :
Best Case    : O(n)
Average Case : O(n²)
Worst Case   : O(n²)
*/

/*
Space Complexity : O(n)
Due to the recursive calls, the space complexity is O(n) because each call adds a new frame to the call stack. 
The maximum depth of recursion is n.
*/
#include <iostream>
using namespace std;

void helper(int arr[], int n, int i) {
    if (i == n) return;
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
        // Swap arr[j] and arr[j - 1]
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
    }
    helper(arr, n, i + 1);
}

void insertionSort(int arr[], int n) {
    helper(arr, n, 1);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
