//Time Complexity : O(logn)

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        int mid;

        while (i <= j) {
            mid = (i + j) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return -1; // Target not found
    }
};




int main() {
    // Example sorted array and target
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    // Create an object of the Solution class
    Solution sol;

    // Call the search function
    int result = sol.search(nums, target);

    // Print the result
    if (result != -1) {
        cout << "Element found at index: " << result <<endl;
    } else {
        cout << "Element not found in the array." <<endl;
    }

    return 0;
}
