/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int i =0,j=0;
        int cnt =0;
        while(j<n)
        {
           if(nums[j]==1) cnt++;
           else
           {
             ans = max(ans,cnt);
             cnt=0;
             i=j;
           }
           j++;
        }
        ans = max(ans,cnt);
        return ans;
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
      if(a==0 && a==1) 
      {
        cout<<"Invalide input Enter only 0 or 1";
        valid = false;
        break;
      }
      nums[i]=a;      
    }
  if(valid)
  {
    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(nums);
    cout<<ans;    
  }
  return 0;
}
