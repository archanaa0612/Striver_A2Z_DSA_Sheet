/*
Time Complexity  : O(n*m)
Space Complexity : O(n*m)
*/
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;




class Solution {
  public:
   
    int longestCommonSubsequence(string text1, string text2) {
        // your code here
         int n = text1.size();
         int m = text2.size();
        
        if(text1==text2) return n;

        vector<vector<int>> dp(n,vector<int>(m,0));
        bool flag = false;
        for(int i =0;i<n;i++)
        {
            if(text2[0]==text1[i])
            {
                flag = true;
                dp[i][0]=1;
            }
            else if(flag) dp[i][0]=1;
        }

        flag = false;

        for(int i =0;i<m;i++)
        {
            if(text1[0]==text2[i])
            {
                flag = true;
                dp[0][i]=1;
            }
            else if(flag) dp[0][i]=1;
        }
        
       

       for(int i =1;i<n;i++)
       {
        for(int j =1;j<m;j++)
        {
            if(text1[i]==text2[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       }

       return dp[n-1][m-1];
    }
};



int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.longestCommonSubsequence(str1, str2) << endl;
    }
    return 0;
}
