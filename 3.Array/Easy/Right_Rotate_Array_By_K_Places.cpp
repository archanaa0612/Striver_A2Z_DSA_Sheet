/*
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

/*
Time Complexity  : O(n) 
Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void reverse(vector<int>& nums,int start , int end)
    {
        while(start<end)
        {
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0 || n<=1 || k==n) return;
        if(k>n) k=k%n;
        
        reverse(nums,0,n-1-k);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);   
    }
};



int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> nums(n);
  for(int i = 0;i<n;i++) cin>>nums[i];
  Solution obj;
  obj.rotate(nums,k);
  for(int i =0;i<n;i++) cout<<nums[i]<<" ";
  return 0;    
}
