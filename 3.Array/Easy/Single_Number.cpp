/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space. 

Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
*/

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a =0;
        for(int i =0;i<nums.size();i++) a = a^nums[i];
        return a;
    }
};

int main()
{
  int n;
  cin>>n;
  vector<int> nums(n);
  bool valid = true;
  for(int i =0;i<n;i++)
    {
      int a;
      cin>>a;
      nums[i]=a;      
    }

    Solution obj;
    int ans = obj.singleNumber(nums);
    cout<<ans;    
  return 0;
}
