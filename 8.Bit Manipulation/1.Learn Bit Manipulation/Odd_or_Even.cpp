/*
Time Complexity  : O(1)
Space Complexity : O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string oddEven(int n) {
        if(n & (1<<0)) return "odd";
        return "even";
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.oddEven(N) << endl;
    }
    return 0;
}
