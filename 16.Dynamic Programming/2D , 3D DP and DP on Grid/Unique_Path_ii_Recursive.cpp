/*
Time Complexity  :  O(2^n*2^m) = O(2^(n+m))
Space Complexity : O(m+n)
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
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        return uniquePathsHelper(obstacleGrid, 0, 0);

        
    }

private:
    int uniquePathsHelper(vector<vector<int>>& obstacleGrid, int i, int j) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // If out of bounds or at an obstacle, return 0
        if (i >= n || j >= m || obstacleGrid[i][j] == 1) return 0;

        // If reached the bottom-right corner, return 1
        if (i == n-1 && j == m-1) return 1;

        // Compute the number of unique paths from the current cell
        int right = uniquePathsHelper(obstacleGrid, i, j + 1);
        int down = uniquePathsHelper(obstacleGrid, i + 1, j);

        return (right + down)%mod;
    }
    
};

//{ Driver Code Starts.
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
