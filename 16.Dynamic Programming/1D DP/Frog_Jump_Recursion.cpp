/*
Time Complexity  : O(2^n) 
Space Complexity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int helper(vector<int>& height,int index)
    {
        if(index==0) return 0;
        
        int jump1 = helper(height,index - 1) + abs(height[index] - height[index-1]);
        int jump2 = INT_MAX;
        if (index > 1)
        jump2 = helper(height,index - 2)+ abs(height[index] - height[index-2]);
        return min(jump1, jump2);
}
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        return helper(height,n-1);
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
