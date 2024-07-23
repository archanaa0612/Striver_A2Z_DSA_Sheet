#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
    bool helper(vector<int> arr, int index,vector<vector<int>>& dp,int sum)
    {
        if(sum==0) return 1;
        if(index==0) return arr[0]==sum;
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        bool notTake = helper(arr,index-1,dp,sum);
        bool take = false;
        if(arr[index]<=sum) take = helper(arr,index-1,dp,sum-arr[index]);
        
        return dp[index][sum] = notTake || take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        if(sum==0) return 1;
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return helper(arr,n-1,dp,sum);
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
