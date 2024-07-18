/*
Time Complexity  : O(n)
Space Compelxity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n==1) return 0;
        vector<int> ans(n);
        ans[n-1]=0;
        ans[n-2]=abs(height[n-1]-height[n-2]);
        if(n<=2) return ans[0];
        
        for(int i =n-3;i>=0;i--)
        {
            int psblAns1 = abs(height[i]-height[i+1])+ans[i+1];
            int psblAns2 = abs(height[i]-height[i+2])+ans[i+2];
            ans[i]=min(psblAns1,psblAns2);
        }
        return ans[0];
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
