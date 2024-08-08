/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
*/

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int a =0;
        for(int i =1;i<=n;i++) a = a^i;
        for(int i =0;i<n;i++) a=a^nums[i];
        return a;
    }
};

int main()
{
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i =0;i<n;i++) cin>>nums[i];

  Solution obj;
  int ans = obj.missingNumber(nums);
  cout<<ans;
  return 0;
}
