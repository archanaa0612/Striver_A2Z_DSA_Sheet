//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int n, int m) {
            queue<pair<int, int>> q;
            q.push({row, col});
            vis[row][col] = 0;
    
            vector<int> dRow = {1, -1, 0, 0};
            vector<int> dCol = {0, 0, 1, -1};
    
            while (!q.empty()) {
                int r  = q.front().first;
                int c = q.front().second;
                q.pop();
    
                for (int i = 0; i < 4; ++i) {
                    int newRow = r + dRow[i];
                    int newCol = c + dCol[i];
    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && vis[newRow][newCol]) {
                        vis[newRow][newCol] = 0;
                        q.push({newRow, newCol});
                    }
                }
            }
 }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 1));

        // Start BFS from the boundary 'O's
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                bfs(grid, vis, 0, i, n, m);
            }
            if (grid[n - 1][i] == 1) {
                bfs(grid, vis, n - 1, i, n, m);
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (grid[i][0] == 1) {
                bfs(grid, vis, i, 0, n, m);
            }
            if (grid[i][m - 1] == 1) {
                bfs(grid, vis, i, m - 1, n, m);
            }
        }
        int ans=0;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j] && vis[i][j]) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
