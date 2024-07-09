#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
void dfs(vector<vector<int>> grid , vector<vector<int>>& vis,int row , int col,int n,int m)
    {
       if(row>=n || col>=m || row<0 || col<0 || !vis[row][col]) return;
       if(grid[row][col]!=1) return;
       vis[row][col]=0;

       dfs(grid,vis,row+1,col,n,m);
       dfs(grid,vis,row-1,col,n,m);
       dfs(grid,vis,row,col-1,n,m);
       dfs(grid,vis,row,col+1,n,m);
    }


    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,1));

        //for rows
        for(int i =0;i<m;i++)
        {
            if(grid[0][i]==1 && vis[0][i])
            {
                 dfs(grid,vis,0,i,n,m);
            }
            if(grid[n-1][i]==1 && vis[n-1][i])
            {
               dfs(grid,vis,n-1,i,n,m);
            }
        }

        //for cols
        for(int i =1;i<n-1;i++)
        {
            if(grid[i][0]==1 && vis[i][0])
            {
               dfs(grid,vis,i,0,n,m);
            }
            if(grid[i][m-1]==1 && vis[i][m-1])
            {
               dfs(grid,vis,i,m-1,n,m);
            }
        }
        int ans =0;
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
