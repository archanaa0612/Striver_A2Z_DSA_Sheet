/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). 
Otherwise, return false.There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
*/



/*
Time Complexity  : O(n) 
Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int idx = -1;
        bool res = true;

        // Find the point of order change (from ascending to descending)
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                idx = i;
                res = false;
                break;  // Break the loop once order change is found
            }
        }

        // If the array was already in order, return true
        if (res) {
            return true;
        }

        // Check the rest of the array for further order changes
        for (int i = idx + 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }

        // Check if the last element is less than the first element
        if (nums[nums.size() - 1] > nums[0]) {
            return false;
        }

        // If there was a single order change and the rest of the array is in order, return true
        return true;
    }
};

int main()
{
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i = 0;i<n;i++) cin>>nums[i];
  Solution obj;
  bool ans = obj.check(nums);
  if(ans) cout<<"true";
  else cout<<"false"; 

  return 0;    
}
