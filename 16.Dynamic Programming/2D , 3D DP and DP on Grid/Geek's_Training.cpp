/*
Time Complexity  : O(3*n)
Space Complexity : O(3*n)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        int ans = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(3));
        for(int i =0;i<3;i++)
        {
            dp[n-1][i]=points[n-1][i];
            ans = max(ans,points[n-1][i]);
            
        }
        if(n==1) return ans;
        
        for(int i = n-2;i>=0;i--)
        {
            dp[i][0] = points[i][0] + max(dp[i+1][1],dp[i+1][2]);
            dp[i][1] = points[i][1] + max(dp[i+1][0],dp[i+1][2]);
            dp[i][2] = points[i][2] + max(dp[i+1][0],dp[i+1][1]);
            
            ans = max(dp[i][0],dp[i][1]);
            ans = max(ans,dp[i][2]);
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
