/*
Time Complexity  : O(n*sum)
Space Complexity : O(n*sum)
*/

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    
    bool isSubsetSum(vector<int> arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    
    // Initialize the dp array for the case where sum is 0
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    
    // Initialize the dp array for the first element if it's within bounds
    if (arr[0] <= sum) {
        dp[0][arr[0]] = 1;
    }
    
    for (int index = 1; index < n; index++) {
        for (int target = 1; target <= sum; target++) {
            int notTake = dp[index - 1][target];
            int take = 0;
            if (arr[index] <= target) {
                take = dp[index - 1][target - arr[index]];
            }
            
            dp[index][target] = notTake | take;
        }
    }
    return dp[n - 1][sum];
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
