/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int print2largest(vector<int> &arr) {
       int largest = INT_MIN;
       int second = -1;
       
       for(a : arr)
       {
           if(a>largest)
           {
               second = largest;
               largest = a;
           }
           else if(a>second && a<largest) second = a;
       }
       if(second==INT_MIN) return -1;
       return second;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}
