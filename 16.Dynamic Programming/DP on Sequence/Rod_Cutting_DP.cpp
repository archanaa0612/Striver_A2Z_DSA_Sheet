/*
Time Complexity  : O(n*n) 
Space Complexity : O(n)
*/


#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        if(n==1) return price[0];
        vector<int> dp(n+1,0);
        dp[1] = price[0];
        dp[2] = max(2*price[0],price[1]);
        
        for(int i =3;i<=n;i++)
        {
            int temp = INT_MIN;
            for(int j =1;j<i;j++)
            {
                temp = max(temp,i/j*dp[j]+dp[i%j]);
            }
            dp[i]=max(temp,price[i-1]);
        }
        return dp[n];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
