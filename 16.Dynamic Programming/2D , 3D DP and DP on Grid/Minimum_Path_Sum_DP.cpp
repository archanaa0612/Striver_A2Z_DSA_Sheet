/*
Time Compelxity  : O(n*m)
Space Complexity : O(n*m)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> minPath(n,vector<int>(m,INT_MAX));
        minPath[0][0]=grid[0][0];

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(i==0 && j==0) continue;
                int left = INT_MAX;
                int top = INT_MAX;

                // if top exists
                if(i-1>=0)
                {
                    left=minPath[i-1][j];
                }
                if(j-1>=0)
                {
                    top=minPath[i][j-1];
                }
                minPath[i][j]=grid[i][j]+min(left,top);
            }
        }
        return minPath[n-1][m-1];
    }
};


int main()
{
  int n ,m;
  cin>>n>>m;
  vector<vector<int>> grid(n,vector<int>(m);
  for(int i =0;i<n;i++)
    {
      for(int j =0;j<m;j++)
        {
          cin>>grid[i][j];
        }
    }

  Solution ob;
  cout<<ob.minPathSum(grid);
  return 0;
}
