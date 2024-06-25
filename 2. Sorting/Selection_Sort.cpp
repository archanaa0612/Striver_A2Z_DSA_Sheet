/*
Time Complexity:
Best Case    : O(n²)
Average Case : O(n²)
Worst Case   : O(n²)

Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in remaining unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    vector<int> arr = {41, 25, 16, 21, 10};
    selectionSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
