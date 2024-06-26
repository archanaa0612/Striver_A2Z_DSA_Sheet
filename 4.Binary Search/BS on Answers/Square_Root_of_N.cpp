#include <iostream>
using namespace std;

class Solution {
public:
    long long int floorSqrt(long long int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        long long int left = 1, right = x, ans = 0;
        while (left <= right) {
            long long int mid = left + (right - left) / 2;

            // If mid*mid is exactly equal to x, return mid
            if (mid * mid == x) {
                return mid;
            }

            // If mid*mid is less than x, discard the left half
            if (mid * mid < x) {
                left = mid + 1;
                ans = mid; // Update the answer to mid
            } else {
                // If mid*mid is greater than x, discard the right half
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    long long int num = 16;
    cout << "The floor square root of " << num << " is " << sol.floorSqrt(num) <<endl;

    num = 20;
    cout << "The floor square root of " << num << " is " << sol.floorSqrt(num) <<endl;

    return 0;
}
