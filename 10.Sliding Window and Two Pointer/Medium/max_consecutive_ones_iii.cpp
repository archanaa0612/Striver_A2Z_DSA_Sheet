/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int totalZero = 0;
        int ans = 0;

        while (j < n) {
            if (nums[j] == 0) totalZero++;
            if (totalZero <= k) {
                ans = max(ans, j - i + 1);
            }
            while (totalZero > k) {
                if (nums[i] == 0) totalZero--;
                i++;
            }
            j++;
        }
        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int result = sol.longestOnes(nums, k);
    cout << "The length of the longest subarray with at most " << k << " zeros is " << result <<endl;

    return 0;
}
