/*
Time Complexity  : O(n*n)
Space Complexity : O(n*n)+O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int helper(int val[], int wt[],int index,int W,vector<vector<int>>& dp)
    {
        if(W==0) return 0;
        if(index==0)
        {
            return W/wt[0]*val[0];
        }
        
        if(dp[index][W]!=-1) return dp[index][W];
        
        int nTake = helper(val,wt,index-1,W,dp);
        int take1 = 0;
        int take2 = 0;
        if(wt[index]<=W)
        {
            take1 = val[index] + helper(val,wt,index-1,W-wt[index],dp);
            take2 = val[index] + helper(val,wt,index,W-wt[index],dp);
        }
        dp[index][W] = max(nTake,max(take1,take2));
        return dp[index][W];
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        if(n==1)
        {
            if(W<wt[0]) return 0;
            return W/wt[0]*val[0];
        }
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
       int ans = helper(val, wt,n-1,W,dp);
       return ans;
    }
};




int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
