#include <bits/stdc++.h>
using namespace std;


/*========================================================================================*/
class Solution {
  public:
    
    void bfs(vector<vector<int>>& grid , vector<vector<int>>& vis,int r , int c,set<vector<pair<int,int>>>& ans)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> Q;
        Q.push({r,c});
        vis[r][c]=1;
        
        int delRow[] = {1,0,-1,0};
        int delCol[] = {0,1,0,-1};
        
        vector<pair<int,int>> res;
        res.push_back({0,0});
        
        while(!Q.empty())
        {
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            for(int i =0;i<4;i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow<n && nRow>=0 && nCol<m && nCol>=0 && !vis[nRow][nCol] && grid[nRow][nCol])
                {
                    res.push_back({nRow-r,nCol-c});
                    vis[nRow][nCol]=1;
                    Q.push({nRow,nCol});
                }
                
            }
        }
        ans.insert(res);
       
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> ans;
        //queue<pair<int,int>> Q;
        
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    bfs(grid,vis,i,j,ans);
                }
            }
        }
        return ans.size();
    }
};
/*========================================================================================*/

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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
