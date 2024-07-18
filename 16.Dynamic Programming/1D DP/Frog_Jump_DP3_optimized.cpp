/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n==1) return 0;
        //vector<int> ans(n);
        int first=0;
        int second=abs(height[n-1]-height[n-2]);
        if(n<=2) return second;
        int ans = INT_MAX;
        
        for(int i =n-3;i>=0;i--)
        {
            int psblAns1 = abs(height[i]-height[i+1])+second;
            int psblAns2 = abs(height[i]-height[i+2])+first;
            ans=min(psblAns1,psblAns2);
            first = second;
            second =ans;
        }
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
