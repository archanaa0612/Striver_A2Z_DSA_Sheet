#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int power = pow(2,n);
        ans.push_back({});
        for(int i =1;i<power-1;i++)
        {
            vector<int> temp;
           for(int j =0;j<n;j++)
           {
             if(i &(1<<j)) temp.push_back(nums[j]);
           }
           ans.push_back(temp);
        }
        ans.push_back(nums);
        return ans;
    }
};

void print(vector<vector<int>>& ans)
{
    int n = ans.size();
    for(int i =0;i<n;i++)
    {
        for(int a : ans[i]) cout<<a<<" ";
        cout<<endl;
    }
}
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
  vector<vector<int>> ans = obj.subsets(nums);
  print(ans);
}
