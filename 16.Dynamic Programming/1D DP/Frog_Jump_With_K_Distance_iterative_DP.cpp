/*
Time Complexity  : O(n*k) 
Space Complexity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeCost(vector<int>& height, int n, int k) {
        if (n <= k) return abs(height[n-1] - height[0]);

        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0; // Cost to reach the last stone from itself is 0

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; j <= k && i + j < n; ++j) {
                dp[i] = min(dp[i], abs(height[i] - height[i + j]) + dp[i + j]);
            }
        }

        return dp[0];
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
