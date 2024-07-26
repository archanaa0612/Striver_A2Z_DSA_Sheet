/*
sum = (totalSum-d)/2;
Time Complexity  : O(log(cnt) + n*sum) 
Space Complexity : O(n*sum)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {

   private:
    const int mod = 1e9+7;
    
    long long mod_pow(long long base, long long exp, long long modulus) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}
public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = 0;
        for(int a : arr) sum+=a;
        int temp = sum-d;
        
        if(temp<0 || temp%2!=0) return 0;
        
        sum = temp/2;
        
        vector<vector<long long int >> dp(n,vector<long long int >(sum+1));
        int cnt =0;
        for(int i =0;i<n;i++)
        {
            if(arr[i]==0) cnt++;
            dp[i][0] = pow(2,cnt);
        }
        
        if(cnt==n)
        {
           return mod_pow(2,cnt,mod);
        }
        
        if(arr[0]<=sum && arr[0]!=0) dp[0][arr[0]]=1;
        
        for(int i =1;i<n;i++)
        {
            for(int target =1;target<=sum;target++)
            {
                long long int  ntake = dp[i-1][target];
                long long int  take =0;
                if(arr[i]<=target) take = dp[i-1][target-arr[i]];
                
                dp[i][target]=(ntake+take)%mod;
            }
        }
        
      return dp[n-1][sum];
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
