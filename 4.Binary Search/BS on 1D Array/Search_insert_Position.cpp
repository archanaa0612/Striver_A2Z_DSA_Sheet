#include <vector>
#include <algorithm> // for lower_bound
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& arr, int m) {
        int n = arr.size();
        
        // If the array is empty or the first element is greater than or equal to m
        if (n == 0 || arr[0] >= m) {
            return 0;
        }

        // If m is greater than the last element
        if (m > arr[n - 1]) {
            return n;
        }

        // Use lower_bound to find the insertion position
        int ans =lower_bound(arr.begin(), arr.end(), m) - arr.begin();
        return ans;
    }
};



int main() {
    Solution sol;
    vector<int> arr = {1, 3, 5, 6};
    int m = 5;
    int index = sol.searchInsert(arr, m);
    cout << "The insert position for " << m << " is " << index <<endl;

    m = 2;
    index = sol.searchInsert(arr, m);
    cout << "The insert position for " << m << " is " << index <<endl;

    m = 7;
    index = sol.searchInsert(arr, m);
    cout << "The insert position for " << m << " is " << index <<endl;

    m = 0;
    index = sol.searchInsert(arr, m);
    cout << "The insert position for " << m << " is " << index <<endl;

    return 0;
}
