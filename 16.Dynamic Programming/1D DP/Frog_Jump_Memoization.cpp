/*
Time Complexity  : O(n)
Space Compelxity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dp;
    
    int minEnergy(vector<int> &height,int start,int n){
        if(start==n){
            return 0;
        }
        if(start==(n-1)){
            return abs(height[n]-height[n-1]);
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        int jump1=minEnergy(height,start+1,n) + abs(height[start]-height[start+1]);
        int jump2=minEnergy(height,start+2,n) + abs(height[start]-height[start+2]);
        dp[start]=(jump1<jump2)?jump1:jump2;
        return dp[start];
        
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        dp.resize(n,-1);
        int ans=minEnergy(height,0,n-1);
        return ans;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
