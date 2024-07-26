/*
Time Complexity  : O(n*n)
Space Complexity : O(n)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1) return triangle[0][0];

        // vector<vector<int>> dp(n,vector<int>(n));
        // dp[0][0]=triangle[0][0];

        vector<int> dp(n);
        dp[0]=triangle[0][0];
        int temp;
        for(int i =1;i<n;i++)
        {
            temp = INT_MAX;
            vector<int> res(n);
            for(int j =0;j<=i;j++)
            {
                int top = INT_MAX;
                if(j!=i)
                {
                    top = dp[j];
                }
                int topLeft = INT_MAX;
                if(j-1>=0)
                {
                    topLeft=dp[j-1];
                }                
                res[j]=triangle[i][j]+min(top,topLeft);
                temp  = min(temp,res[j]);                         
            }
            dp=res;            
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
