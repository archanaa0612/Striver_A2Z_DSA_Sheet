/*
Time Complexity  : O(n*m)
Space Complexity : O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9+7;
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Code here
        // If the starting or ending point is an obstacle, return 0
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        vector<vector<int>> DP(n, vector<int>(m, 0));

        // Initialize the starting point
        DP[0][0] = 1;

        // Fill the first row
        for (int j = 1; j < m; ++j) {
            if (obstacleGrid[0][j] == 1) {
                DP[0][j] = 0;
            } else {
                DP[0][j] = DP[0][j - 1];
            }
        }

        // Fill the first column
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[i][0] == 1) {
                DP[i][0] = 0;
            } else {
                DP[i][0] = DP[i - 1][0];
            }
        }

        // Fill the rest of the DP table
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    DP[i][j] = 0;
                } else {
                    DP[i][j] = (DP[i - 1][j] + DP[i][j - 1])%mod;
                }
            }
        }

        return DP[n - 1][m - 1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> obstacleGrid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            obstacleGrid.push_back(temp);
        }

        Solution obj;
        cout << obj.uniquePathsWithObstacles(grid) << "\n";
    }
    return 0;
}
