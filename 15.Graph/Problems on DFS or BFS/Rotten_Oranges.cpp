#include<bits/stdc++.h>
using namespace std;

=======================================================================================
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> Q;

        int cnt =0;

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    Q.push({i,j});
                    visited[i][j]=1;
                    cnt++;
                }
                else if(grid[i][j]==0)
                {
                    visited[i][j]=1;
                    cnt++;
                }
            }
        }
       // cout<<cnt<<endl;

        int delRow[] = {1,0,-1,0};
        int delCol[] = {0,1,0,-1};
        int ans = 0;
        while(!Q.empty())
        {
            bool flag = false;
            int s = Q.size();
            //cout<<"size  "<<s<<endl;
            for(int i =0;i<s;i++)
            {
                int row = Q.front().first;
                int col = Q.front().second;
                Q.pop();
                for(int j =0;j<4;j++)
                {
                    int nRow = row + delRow[j];
                    int nCol = col + delCol[j];
                    if(nRow<n && nRow>=0 && nCol<m && nCol>=0 && !visited[nRow][nCol])
                    {
                        visited[nRow][nCol] = 1;
                        Q.push({nRow,nCol});
                        cnt++;
                        //cout<<"cnt  "<<cnt<<endl;
                        flag = true;
                    }
                }
            }
           if(flag) ans++;
        }
        if(cnt!=n*m) return -1;
        return ans;
    }
};
==================================================================================
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
