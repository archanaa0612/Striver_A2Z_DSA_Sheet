//Time Complexity : O(n)

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findFirstPosition(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int firstPos = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                firstPos = mid;
                right = mid - 1; // Continue searching in the left half
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return firstPos;
    }

    int findLastPosition(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int lastPos = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                lastPos = mid;
                left = mid + 1; // Continue searching in the right half
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return lastPos;
    }

vector<int> searchRange(vector<int>& arr, int x) {
        int firstPos = findFirstPosition(arr, x);
        if (firstPos == -1) { // If target is not found
            return {-1, -1};
        }
        int lastPos = findLastPosition(arr, x);
        return {firstPos, lastPos};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(arr, target);
    cout << "First and last positions of " << target << " are: " 
              << result[0] << ", " << result[1] <<endl;

    target = 6;
    result = sol.searchRange(arr, target);
    scout << "First and last positions of " << target << " are: " 
              << result[0] << ", " << result[1] <<endl;

    return 0;
}
