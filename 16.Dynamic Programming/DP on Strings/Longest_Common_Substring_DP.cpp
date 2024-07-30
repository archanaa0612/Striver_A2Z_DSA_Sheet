/*
Time Complexity  : O(n*m)
Space Complexity : O(n*m)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = s1[0]==s2[0];
        int ans = INT_MIN;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(i==0 && j==0) continue;
                
                if(s1[i]==s2[j])
                {
                    if(i==0 || j==0) dp[i][j]=1;
                    else  dp[i][j]=dp[i-1][j-1]+1;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
