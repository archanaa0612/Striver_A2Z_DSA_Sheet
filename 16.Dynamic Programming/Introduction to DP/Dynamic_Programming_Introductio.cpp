#include <bits/stdc++.h>
using namespace std;



const int mod = 1e9+7;
class Solution {
  private:
    long long int topDownHelper(int n , vector<long long int>& dp)
    {
        if(n<=1)
        {
            dp[n]=n;
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]= (topDownHelper(n-1,dp)+topDownHelper(n-2,dp))%mod;
    }
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,-1);
         return topDownHelper(n,dp);
        
    }
    long long int bottomUp(int n) {
        // code here
        if(n<=1) return n;
        long long int first  = 0;
        long long int second = 1;
        
        long long int ans = 0;
        for(int i = 2;i<=n;i++)
        {
            ans = (first + second)%mod;
            first = second;
            second = ans;
        }
        return second;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
