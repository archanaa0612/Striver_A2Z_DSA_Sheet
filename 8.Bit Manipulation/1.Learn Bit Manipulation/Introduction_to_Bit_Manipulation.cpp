/*
Time Complexity  : O(1)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        i--;
        int ith = pow(2,i);
        if(num & (1<<i))
        {
            cout<<1<<" "<<num<<" "<<num-ith;
        }
        else 
        {
            cout<<0<<" "<<num+ith<<" "<<num;   
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
