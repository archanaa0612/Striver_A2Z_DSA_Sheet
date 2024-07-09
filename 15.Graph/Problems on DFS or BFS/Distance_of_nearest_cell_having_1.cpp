#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> Q;

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j])
                {
                    visited[i][j]=1;
                    Q.push({{i,j},0});
                }
            }
        }

    int delRow[] = {1,0,-1,0};
    int delCol[] = {0,1,0,-1};
        while(!Q.empty())
        {
            int row = Q.front().first.first;
            int col = Q.front().first.second;
            int dis = Q.front().second;
            Q.pop();

            for(int i =0;i<4;i++)
            {
                int nRow = row+delRow[i];
                int nCol = col+delCol[i];
                int step = dis+1;
                if(nRow<n && nRow>=0 && nCol<m && nCol>=0 && !visited[nRow][nCol] && !grid[nRow][nCol])
                {
                    visited[nRow][nCol]=1;
                    Q.push({{nRow,nCol},step});
                    ans[nRow][nCol]=step;
                }
            }
            dis++;
        }
        return ans;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
