/*
Time Complexity  : O(n*k)
Space Complexity : (n)
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimizeCostUtil(vector<int>& height, int n, int k, int currentIndex, vector<int>& dp) {
        // Base case: if we have reached the last stone
        if (currentIndex == n - 1) return 0;
        
        // If the result is already computed, return it
        if (dp[currentIndex] != -1) return dp[currentIndex];

        int minCost = INT_MAX;
        for (int j = 1; j <= k && currentIndex + j < n; ++j) {
            int cost = abs(height[currentIndex] - height[currentIndex + j]) + 
                       minimizeCostUtil(height, n, k, currentIndex + j, dp);
            minCost = min(minCost, cost);
        }

        // Memoize the result
        return dp[currentIndex] = minCost;
    }

    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, -1); // Initialize the memoization array with -1
        return minimizeCostUtil(height, n, k, 0, dp);
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
