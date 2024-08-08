/*
Time Complexity  : O(n) 
Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i =0,j=1;
        while(j<n)
        {
            if(nums[i]==nums[j]) j++;
            else if((j-i)==1 && nums[i]!=nums[j])
            {
                j++;
                i++;
            }
            else{
                swap(nums[i+1],nums[j]);
                i++;
                j++;
            }
        }
        return i+1;
    }
};

int main()
{
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i = 0;i<n;i++) cin>>nums[i];
  Solution obj;
  int lastIndex = obj.removeDuplicates(nums);

  for(int i =0;i<lastIndex;i++) cout<<nums[i]<<" ";

  return 0;    
}
