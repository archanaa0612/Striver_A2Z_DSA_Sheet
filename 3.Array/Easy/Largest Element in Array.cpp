/*Time Complexity   : O(n)*/
/* Space Complexity : O(1)*/

#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
#include <algorithm> // For std::max
using namespace std;

class Solution {
public:
    // Function to find the largest element in the array
    int largest(svector<int> &arr, int n) {
        int ans = INT_MIN; // Initialize ans to the minimum possible integer
        for(int i = 0; i < n; i++) {
            ans = max(ans, arr[i]); // Update ans if arr[i] is greater
        }
        return ans; // Return the largest element
    }
};

int main() {
    // Sample array
    vector<int> arr = {1, 8, 7, 56, 90};

    // Size of the array
    int n = arr.size();

    // Create an object of Solution class
    Solution sol;

    // Find the largest element in the array
    int largestElement = sol.largest(arr, n);

    // Print the largest element
    std::cout << "The largest element in the array is: " << largestElement << std::endl;

    return 0;
}
