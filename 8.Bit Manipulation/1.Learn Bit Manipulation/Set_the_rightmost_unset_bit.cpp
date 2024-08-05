/*
Time Complexity  : O(log(n))
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBit(int n) {
      
        int i = log(n)+1;
        
        for(int j = 0;j<=i;j++)
        {
            if(n & (1<<j)) continue;
             n = n+pow(2,j);
             return n;
        }
        return n+pow(2,i+1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
