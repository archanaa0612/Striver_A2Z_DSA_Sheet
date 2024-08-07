/*
Time Complexity: O(N).
Auxiliary Space: O(N) (Recursive).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printGfg(int N) {
        if(N==1)
        {
            cout<<"GFG ";
            return;
        }
        printGfg(N-1); 
        cout<<"GFG ";
    }
};

int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printGfg(N);
        cout << "\n";
    }
    return 0;
}
