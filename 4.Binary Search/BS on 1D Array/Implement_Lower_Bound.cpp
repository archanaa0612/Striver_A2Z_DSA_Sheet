#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findFloor(vector<long long>& v, long long n, long long x) {
        // Initialize the variables for binary search
        long long left = 0, right = n - 1;
        int result = -1; // Initialize result to -1 indicating no floor found if x is smaller than all elements

        // Perform binary search
        while (left <= right) {
            long long mid = left + (right - left) / 2;

            // If the element at mid is equal to x, it is the floor
            if (v[mid] == x) {
                return mid;
            }
            
            // If the element at mid is less than x, it is a potential floor
            if (v[mid] < x) {
                result = mid;
                left = mid + 1; // Move to the right half
            } else {
                // If the element at mid is greater than x, move to the left half
                right = mid - 1;
            }
        }

        // Return the index of the floor element
        return result;
    }
};



int main() {
    Solution sol;
    vector<long long> arr = {1, 2, 4, 6, 10, 12, 14};
    long long x = 5;
    int index = sol.findFloor(arr, arr.size(), x);

    if (index != -1) {
        cout << "The floor of " << x << " is " << arr[index] << " at index " << index <<endl;
    } else {
        cout << "There is no floor of " << x << " in the array." <<endl;
    }

    return 0;
}
