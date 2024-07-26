/*
Time Complexity : O(n*n)
Space Compleity : O(n*n)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1) return triangle[0][0];

        vector<vector<int>> dp(n,vector<int>(n));
        dp[0][0]=triangle[0][0];

        int temp;
        for(int i =1;i<n;i++)
        {
            temp = INT_MAX;
            for(int j =0;j<=i;j++)
            {
                int top = INT_MAX;
                if(j!=i)
                {
                    top = dp[i-1][j];
                }
                int topLeft = INT_MAX;
                if(j-1>=0)
                {
                    topLeft=dp[i-1][j-1];
                }                
                dp[i][j]=triangle[i][j]+min(top,topLeft);
                temp  = min(temp,dp[i][j]);
                //cout<<temp<<"  ";                
            }
            //cout<<endl;
        }

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<=i;j++)
            {
                cout<<dp[i][j]<<"  ";
            }
            cout<<endl;
        }
        return temp;
    }
};


int main()
{
  int n;
  cin>>n;
  vector<vector<int>> triangle(n);

  for(int i =0;i<n;i++)
    {
      vector<int> temp(i+1);
      for(int j =0;j<=i;j++)
        {
          cin>>temp[j];
        }
      triangle.push_back(temp);
    }

  Solution ob;
  cout<<ob.minimumTotal(triangle);
}

