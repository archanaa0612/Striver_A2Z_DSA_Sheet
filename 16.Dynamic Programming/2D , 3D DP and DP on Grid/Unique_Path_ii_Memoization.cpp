/*
Time Complexity  : O(n*m)
Space Complexity : O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
 const int mod = 1e9+7;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Code here

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // If the starting or ending point is an obstacle, return 0
        if (obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1) return 0;

        // Initialize a memoization table with -1
        vector<vector<int>> memo(n, vector<int>(m, -1));

        return uniquePathsHelper(obstacleGrid, memo, 0, 0);
    }
    
private:
    int uniquePathsHelper(vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo, int i, int j) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // If out of bounds or at an obstacle, return 0
        if (i >= n || j >= m || obstacleGrid[i][j] == 1) return 0;

        // If reached the bottom-right corner, return 1
        if (i == n-1 && j == m-1) return 1;

        // If already computed, return the stored value
        if (memo[i][j] != -1) return memo[i][j];

        // Compute the number of unique paths from the current cell
        int right = uniquePathsHelper(obstacleGrid, memo, i, j + 1);
        int down = uniquePathsHelper(obstacleGrid, memo, i + 1, j);

        // Store the result in the memoization table
        memo[i][j] = (right + down)%mod;

        return memo[i][j];
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
        cout << obj.uniquePathsWithObstacles(obstacleGrid) << "\n";
    }
    return 0;
}
