/*
Time Complexity  : O(log(n))
Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start==goal) return 0;
        int maxi = max(start,goal);
        int bits = floor(log2(maxi));
        
        int ans =0;
        for(int i =0;i<=bits;i++)
        {
             if((start & (1<<i)) != (goal & (1<<i))) ans++;
        }
        return ans;
    }
};

int main()
{
  int start,goal;
  cin>>start>>goal;
  Solution obj;
  int ans = obj.minBitFlips(start,goal);
  cout<<ans;
}
