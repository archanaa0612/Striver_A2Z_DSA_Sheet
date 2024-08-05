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
        for(int i =0;i<nums.size();i++)
        {
            a = a^nums[i];
        }
        return a;
    }
};

int main()
{
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i =0;i<n;i++)
    {
      cin>>nums[i];
    }
  Solution obj;
  int ans = obj.singleNumber(nums);
  cout<<ans;
  return 0;
}
