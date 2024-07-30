/*
Time Complexity  : O(n*n)
Space Complexity : O(n*n)
*/


#include<bits/stdc++.h>
using namespace std;


class Solution{
  private:
     int longestCommonSubsequence(string text1, string text2) {
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
  
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        string B = A;
        
        int i =0;
        int j = n-1;
        while(i<j)
        {
            swap(B[i],B[j]);
            i++;
            j--;
        }
        
        return longestCommonSubsequence(A,B);
    }
};


int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
