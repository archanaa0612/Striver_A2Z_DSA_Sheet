/*
Time complexity  : O(n*m)
Space Complexity : O(n*m)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find total number of unique paths.
    int uniquePaths(int m, int n)
    {
        //code here
        if(n==1 || m==1) return 1;
        if(n==1 && m==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));

        // mark the last row as 1 
        for(int i =0;i<n-1;i++)
        {
            dp[m-1][i]=1;
        }

        // mark the last col as 1
        for(int i =0;i<m-1;i++)
        {
            dp[i][n-1]=1;
        }

        for(int i =m-2;i>=0;i--)
        {
            for(int j = n-2;j>=0;j--)
            {
                //if right exists
                if(j+1<n)  dp[i][j]=dp[i][j]+dp[i][j+1];

                //if down exists
                if(i+1<m) dp[i][j]=dp[i][j]+dp[i+1][j];               
            }
        }
        return dp[0][0];
    }
};



int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int m,n;
        cin>>m>>n;
        Solution ob;
        //calling uniquePaths() function
        cout << ob.uniquePaths(m,n) << endl;
    }
}
