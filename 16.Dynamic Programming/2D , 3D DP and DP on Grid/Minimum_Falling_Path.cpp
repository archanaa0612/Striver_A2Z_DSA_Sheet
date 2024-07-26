/*
Time Complexity  : O(n*n) 
Space Complexity : O(n*n)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n));
        dp[0]=matrix[0];
        
        int temp = INT_MIN; 
        for(int i =1;i<n;i++)
        {
            temp = INT_MAX;
            for(int j =0;j<n;j++)
            {
                int top      = dp[i-1][j];
                int topRight = INT_MAX;
                int topLeft  = INT_MAX;

                if(j-1>=0)
                {
                    topLeft=dp[i-1][j-1];
                }
                if(j+1<n)
                {
                    topRight=dp[i-1][j+1];
                }
                dp[i][j]=matrix[i][j]+min(top,min(topLeft,topRight));
                temp = min(temp,dp[i][j]);
               // cout<<temp<<"  ";
            }
            //cout<<endl;
        }
        if(temp==INT_MIN)
        {
            temp = INT_MAX;
            for(int i =0;i<n;i++)
            {
                 temp=min(temp,dp[0][i]);
            }
        }
        return temp;
    }
};

int main(){

  int n;
  cin>>n;
  vector<vector<int>> matrix(n,vector<int>(n));
  for(int i =0;i<n;i++)
    {
      for(int j =0;j<n;j++)
        {
          cin>>matrix[i][j];
        }
    }
}
