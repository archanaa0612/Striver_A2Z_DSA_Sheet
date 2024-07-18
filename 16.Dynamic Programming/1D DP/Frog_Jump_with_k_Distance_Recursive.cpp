/*
Time Complexity  : O(k^n) in worst case
Space Complexity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimizeCostUtil(vector<int>& height, int n, int k, int currentIndex) {
        // Base case: if we have reached the last stone
        if (currentIndex == n - 1) return 0;

        int minCost = INT_MAX;
        for (int j = 1; j <= k && currentIndex + j < n; ++j) {
            int cost = abs(height[currentIndex] - height[currentIndex + j]) +minimizeCostUtil(height, n, k, currentIndex + j);
            minCost = min(minCost, cost);
        }

        return minCost;
    }

    int minimizeCost(vector<int>& height, int n, int k) {
        return minimizeCostUtil(height, n, k, 0);
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
