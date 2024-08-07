/*
Time Complexity: O(log(min(a, b))
Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long  gcd(long long a, long long b)
     {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

    vector<long long> lcmAndGcd(long long a, long long b) {
        long long GCD =  gcd(a,b);
        long long LCM = (a*b)/GCD;
        
        return {LCM,GCD};
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
