/*
Time Complexity  : O(1)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findXOR(int l, int r) {
        int start =0;
        int end=0;
        if(l%2!=0)
        {
            start=l;
            l++;
        }
        if(r%2==0)
        {
            end = r;
            r--;
        }
        int ans = 0;
        if((r-l+1)%4!=0) ans=1;
        ans = ans^start^end;
        return ans;
    }
};

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
