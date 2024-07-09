//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void bfs(vector<vector<char>>& mat, vector<vector<int>>& vis, int row, int col, int n, int m) {
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
    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && mat[newRow][newCol] == 'O' && vis[newRow][newCol]) {
                        vis[newRow][newCol] = 0;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 1));

        // Start BFS from the boundary 'O's
        for (int i = 0; i < m; i++) {
            if (mat[0][i] == 'O') {
                bfs(mat, vis, 0, i, n, m);
            }
            if (mat[n - 1][i] == 'O') {
                bfs(mat, vis, n - 1, i, n, m);
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (mat[i][0] == 'O') {
                bfs(mat, vis, i, 0, n, m);
            }
            if (mat[i][m - 1] == 'O') {
                bfs(mat, vis, i, m - 1, n, m);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
